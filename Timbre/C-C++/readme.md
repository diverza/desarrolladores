# Timbrar desde C/C++

Para poder ejecutar los ejemplos en Windows necesario tener Visual Studio instalado en la version 2005 o superior, para Unix/Linux/OSX es necesario tener instalado gcc y cURL.

## Parametros de prueba

- La URL de prueba es: **http://213.239.207.18:4444/stamp**

- El token de seguridad de prueba es: **abc**

- El RFC emisor de prueba es: **AAA010101AAA**

- El certificado de prueba lo puedes descargar de: **----LLENAR-----**

## Windows
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la "Developer Command Prompt" usando:

```sh
# Timbrar
C:\>cl timbrar.c libcurl.lib /I include
C:\>timbrar

# Cancelar
C:\>cl cancelar.c libcurl.lib /I include
C:\>cancelar
``

## Unix/Linux/OSX
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la terminal usando:

```sh
# Timbrar
$ gcc timbrar.c -o timbrar -lcurl
$ ./timbrar

# Cancelar
$ gcc cancelar.c -o cancelar -lcurl
$ ./cancelar
```