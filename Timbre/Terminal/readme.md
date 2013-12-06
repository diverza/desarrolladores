# Timbrar desde Terminal

Para poder ejecutar los ejemplos es necesario tener cURL instalado.

## Parametros de prueba

- La URL de prueba es: **http://213.239.207.18:4444/stamp**

- El token de seguridad de prueba es: **abc**

- El RFC emisor de prueba es: **AAA010101AAA**

- El certificado de prueba lo puedes descargar de: **----LLENAR-----**

## Windows
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la linea de comandos usando:

```sh
# Timbrar
C:\>"C:\Program Files\cURL\bin\cURL.exe" http://213.239.207.18:4444/stamp -X POST --data @cfd.xml -H "x-auth-token: abc" -i

# Cancelar
C:\>"C:\Program Files\cURL\bin\cURL.exe" http://213.239.207.18:4444/stamp/cancel -X POST --data @cancelar.xml -H "x-auth-token: abc" -i
```

## Unix/Linux/OSX
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la terminal usando:

```sh
# Timbrar
$ cURL http://213.239.207.18:4444/stamp -X POST --data @cfd.xml -H "x-auth-token: abc" -i

# Cancelar
$ cURL http://213.239.207.18:4444/stamp/cancel -X POST --data @cancelar.xml -H "x-auth-token: abc" -i
```