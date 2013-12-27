# Timbrar desde Terminal

Para poder ejecutar los ejemplos es necesario tener cURL instalado.

## Parametros de prueba

- La URL de prueba es: **http://staging.diverza.com/stamp**

- El token de seguridad de prueba es: **ABCD1234**

- El RFC emisor de prueba es: **AAA010101AAA**

## Windows
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la linea de comandos usando:

```sh
# Timbrar
C:\>"C:\Program Files\cURL\bin\cURL.exe" http://staging.diverza.com/stamp -X POST --data @cfd.xml -H "x-auth-token: ABCD1234" -i

# Cancelar
C:\>"C:\Program Files\cURL\bin\cURL.exe" http://staging.diverza.com/stamp/<Agregar UUID del Timbre a Cancelar> -X DELETE -H "x-auth-token: ABCD1234" -i

## Ejemplo cURL http://staging.diverza.com/stamp/222fe27b-2c49-4dba-95d4-cd61c0514e63 -X DELETE -H "x-auth-token: ABCD1234" -i
```

## Unix/Linux/OSX
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la terminal usando:

```sh
# Timbrar
$ cURL http://staging.diverza.com/stamp -X POST --data @cfd.xml -H "x-auth-token: ABCD1234" -i

# Cancelar
$ cURL http://staging.diverza.com/stamp/<Agregar UUID del Timbre a Cancelar> -X DELETE -H "x-auth-token: ABCD1234" -i

## Ejemplo cURL http://staging.diverza.com/stamp/222fe27b-2c49-4dba-95d4-cd61c0514e63 -X DELETE -H "x-auth-token: ABCD1234" -i
```