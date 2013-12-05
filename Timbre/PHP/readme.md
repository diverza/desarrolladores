# Timbrar desde PHP

Para poder ejecutar los ejemplos es necesario tener PHP instalado en la version 4.0.4 o superior.

## Parametros de prueba

- La URL de prueba es: **http://213.239.207.18:4444/stamp**

- El token de seguridad de prueba es: **abc**

- El RFC emisor de prueba es: **AAA010101AAA**

- El certificado de prueba lo puedes descargar de: **----LLENAR-----**

## Windows
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la linea de comandos usando:

```sh
# Timbrar
C:\>"C:\Program Files (x86)\PHP\v5.3\php.exe" timbrar.php


# Cancelar
C:\>"C:\Program Files (x86)\PHP\v5.3\php.exe" cancelar.php
```

**Nota** Es posible que el archivo php.exe se encuentre en una ruta distinta dependiendo de la configuración del sistema.

## Unix/Linux/OSX
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la terminal usando:

```sh
# Timbrar
$ php timbrar.php

# Cancelar
$ php cancelar.php
```