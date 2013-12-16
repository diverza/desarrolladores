# Timbrar desde Go

Para poder ejecutar los ejemplos en Windows necesario tener Go instalado en su versión 1.2 o superior.

## Parametros de prueba

- La URL de prueba es: **http://213.239.207.18:4444/stamp**

- El token de seguridad de prueba es: **abc**

- El RFC emisor de prueba es: **AAA010101AAA**

- El certificado de prueba lo puedes descargar de: **----LLENAR-----**

## Windows
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la linea de comandos usando:

```sh
# Timbrar
C:\> "C:\GO\bin\go.exe" run timbrar.go

# Cancelar
C:\> "C:\GO\bin\go.exe" run cancelar.go
```

## Unix/Linux/OSX
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la terminal usando:

```sh
# Timbrar
$ go run timbrar.go

# Cancelar
$ go run cancelar.go
```