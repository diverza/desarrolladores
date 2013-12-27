# Timbrar desde Go

Para poder ejecutar los ejemplos en Windows necesario tener Go instalado en su versión 1.2 o superior.

## Parametros de prueba

- La URL de prueba es: **http://staging.diverza.com/stamp**

- El token de seguridad de prueba es: **ABCD1234**

- El RFC emisor de prueba es: **AAA010101AAA**

## Windows
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la linea de comandos usando:

```sh
# Timbrar
C:\> "C:\GO\bin\go.exe" run timbrar.go

# Cancelar
1) Agregar el UUID del CFDI a cancelar en el archivo cancelar.go:13

2) C:\> "C:\GO\bin\go.exe" run cancelar.go
```

## Unix/Linux/OSX
Para ejecutar un timbrado de prueba unicamente ejecuta el script desde la terminal usando:

```sh
# Timbrar
$ go run timbrar.go

# Cancelar
1) Agregar el UUID del CFDI a cancelar en el archivo cancelar.go:13

2) $ go run cancelar.go
```