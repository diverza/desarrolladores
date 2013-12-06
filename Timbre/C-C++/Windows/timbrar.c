#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

static void write_callback_function(void *ptr, size_t size, size_t nmemb, void *userp)
{
  char **response_ptr =  (char**)userp;
  *response_ptr = strdup(ptr);
}

struct WriteStructure 
{
  const char *readptr;
  long sizeleft;
};

static size_t read_callback_function(void *ptr, size_t size, size_t nmemb, void *userp)
{ 
  struct WriteStructure *writeStructure = (struct WriteStructure *)userp;

  if(size*nmemb < 1)
  {
   return 0;
  }

  if(writeStructure->sizeleft) 
  {
    *(char *)ptr = writeStructure->readptr[0]; 
    writeStructure->readptr++;                 
    writeStructure->sizeleft--;               
    return 1;                        
  }
  return 0;                          
}

static char* read_cfd_file()
{
  char *cfd;
  long cfd_file_size;

  FILE *cfd_file = fopen("cfd.xml", "rb");

  fseek(cfd_file, 0, SEEK_END);
  cfd_file_size = ftell(cfd_file);
  rewind(cfd_file);
  cfd = malloc(cfd_file_size * (sizeof(char)));
  fread(cfd, sizeof(char), cfd_file_size, cfd_file);
  fclose(cfd_file);
  
  return cfd;
}

int main(void)
{
  /* Recuerda que:
  // La URL de prueba es: http://213.239.207.18:4444/stamp
  // El token de seguridad de prueba es: abc
  // El RFC emisor de prueba es: AAA010101AAA
  // El certificado de prueba lo puedes descargar de: ----LLENAR----- */
  char *cfd;
  char *stamp;
  long response_code;
  CURL *curl;
  CURLcode result;
  struct curl_slist *headers = NULL;
  struct WriteStructure writeStructure;
  
  result = curl_global_init(CURL_GLOBAL_DEFAULT);
  if(result != CURLE_OK) 
  {
    fprintf(stderr, "Error en curl_global_init(): %s\n", curl_easy_strerror(result));
    return 1;
  }

  curl = curl_easy_init();
  if(curl) 
  {
    cfd = read_cfd_file();

    writeStructure.readptr = cfd;
    writeStructure.sizeleft = (long)strlen(cfd);

    curl_easy_setopt(curl, CURLOPT_URL, "http://213.239.207.18:4444/stamp");

    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    headers = curl_slist_append(headers, "x-auth-token: abc");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER,headers);

    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback_function);
    curl_easy_setopt(curl, CURLOPT_READDATA, &writeStructure);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, writeStructure.sizeleft);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_function);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stamp);

    result = curl_easy_perform(curl);
    
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    curl_easy_cleanup(curl);

    printf("Codigo HTTP: %lu\n", response_code);
    printf("Timbre: %s", stamp);  
  }

  curl_global_cleanup();
  return 0;
}