#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>

// Estructura necesaria para la escritura del cuerpo de la petición
struct WriteStructure 
{
  const char *readptr;
  long sizeleft;
};

// Funcion de lectura para la respuesta del servicio de timbrado
static void write_callback_function(void *ptr, size_t size, size_t nmemb, void *userp)
{
  char **response_ptr =  (char**)userp;
  *response_ptr = strdup(ptr);
}

// Funcion de escritura para el cuerpo de la petición HTTP
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

// Function de lectura para el archivo XML que contiene el CFD a timbrar
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
  // La URL de prueba es: http://staging.diverza.com/stamp
  // El token de seguridad de prueba es: ABCD1234
  // El RFC emisor de prueba es: AAA010101AAA */
  char *cfd;
  char *stamp;
  long response_code;
  CURL *curl;
  CURLcode result;
  struct curl_slist *headers = NULL;
  struct WriteStructure writeStructure;
  
  // Inicializamos todas las dependencias de la libreria de cURL
  result = curl_global_init(CURL_GLOBAL_DEFAULT);
  if(result != CURLE_OK) 
  {
    fprintf(stderr, "Error en curl_global_init(): %s\n", curl_easy_strerror(result));
    return 1;
  }

  // Inicializamos la libreria de cURL
  curl = curl_easy_init();
  if(curl) 
  {
    /* Por facilidad leemos el CFD a timbrar del archivo cfd.xml que se encuentra
    * en la carpeta actual */
    cfd = read_cfd_file();

    // Guardamos el CFD en una estructura que nos servira para escribir en el cuerpo
    // de la petición
    writeStructure.readptr = cfd;
    writeStructure.sizeleft = (long)strlen(cfd);

    // Agregamos en URL del servicio de timbrado
    curl_easy_setopt(curl, CURLOPT_URL, "http://staging.diverza.com/stamp");

    // Para solicitar el timbrado es necesario enviar una solicitud HTTP usando el verbo POST
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    /* Agregamos un header a la petición indicando el token que utilizaremos, en este caso el de 
     * prueba 'ABCD1234'. Este debe ser modificado una vez que querramos utilizar nuestra propia cuenta
     * para timbrar */
    headers = curl_slist_append(headers, "x-auth-token: ABCD1234");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER,headers);

    /* Damos de alta la funcion que utilizaremos para escribir el cuerpo del mensaje para la
    * transacción */
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback_function);
    curl_easy_setopt(curl, CURLOPT_READDATA, &writeStructure);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, writeStructure.sizeleft);

    /* Damos de alta la funcion que utilizaremos para recibir la respuesta de la petición del 
     * timbre */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_function);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stamp);

    // Finalmente ejecutamos la petición al servidor
    result = curl_easy_perform(curl);
    
    // Obtenemos el codigo de respuesta del servidor
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Limpiados la ejecución de cURL
    curl_easy_cleanup(curl);

    printf("Codigo HTTP: %lu\n", response_code);
    printf("Timbre: %s", stamp);  
  }

  // Limpiamos la libreria de cURL
  curl_global_cleanup();
  return 0;
}