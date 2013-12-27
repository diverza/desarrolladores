# -*- coding: UTF-8 -*-
import httplib, urllib

# Creamos una variable para guardar el el UUID del CFDI Timbrado, probablemente necesites
# cambiar este valor por un UUID valido.
UUID = "<Agregar UUID del Timbre a Cancelar>"

# Recuerda que:
# La URL de prueba es: http://staging.diverza.com/stamp
# El token de seguridad de prueba es: ABCD1234
# El RFC emisor de prueba es: AAA010101AAA

# Creamos una nueva instancia del objeto HTTPConnection con la dirección URL 
# del servicio de timbrado y el puerto que utilizaremos, en este caso 80
connection = httplib.HTTPConnection("staging.diverza.com")

# Agregamos un header a la petición indicando el token que utilizaremos, en este caso el de 
# prueba 'ABCD1234'. Este debe ser modificado una vez que querramos utilizar nuestra propia cuenta
# para timbrar
headers = {"x-auth-token": "ABCD1234"}

# Solicitamos la cancelación del timbre enviando una petición HTTP usando el metodo DELETE a la URL 
# "/stamp/:uuid" y agregamos tambien el header previamente instanciado.
connection.request("DELETE", "/stamp/" + UUID, '', headers)

# Extraemos la respuesta del servidor de timbrado
response = connection.getresponse()

# Obtenemos el codigo de respuesta del servidor y el mensaje de respuesta
response_code = str(response.status) + " " + response.reason
response_message = response.read()

# Cerramos la conexión con el servicio
connection.close()

print "Codigo HTTP: " + response_code
print "Mensaje: " + response_message