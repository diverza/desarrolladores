# Timbrar desde Python

Para poder ejecutar los ejemplos es necesario tener Python instalado en la version 2.7.6 o similar y en el caso de Windows es necesario tener instalada la libreria httplib2 (Es preferible tener instalado Python usando ActivePython).

## Parametros de prueba

- La URL de prueba es: **http://213.239.207.18:4444/stamp**

- El token de seguridad de prueba es: **abc**

- El RFC emisor de prueba es: **AAA010101AAA**

- El certificado de prueba lo puedes descargar de: **----LLENAR-----**

## Windows
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la linea de comandos usando:

```sh
# Timbrar
C:\> "C:\Python\python.exe" timbrar.py

# Cancelar
C:\> "C:\Python\python.exe" cancelar.py
```

**Nota** Es posible que el archivo python.exe se encuentre en una ruta distinta dependiendo de la configuración del sistema.

## Unix/Linux/OSX
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la terminal usando:

```sh
# Timbrar
$ python timbrar.py

# Cancelar
$ python cancelar.py
```