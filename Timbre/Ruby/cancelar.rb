# -*- coding: UTF-8 -*-
require "net/http"

# Creamos una variable para guardar el el UUID del CFDI Timbrado, probablemente necesites
# cambiar este valor por un UUID valido.
UUID = "<Agregar UUID del Timbre a Cancelar>"

# Recuerda que:
# La URL de prueba es: http://staging.diverza.com/stamp
# El token de seguridad de prueba es: ABCD1234
# El RFC emisor de prueba es: AAA010101AAA

# Creamos una nueva instancia del objeto HTTP con la dirección URL del servicio de timbrado
# y el puerto que utilizaremos, en este caso 80
http = Net::HTTP.new("staging.diverza.com", 80)

# Para solicitar el timbrado es necesario enviar una solicitud HTTP usando el verbo DELETE a la
# URL "/stamp/:uuid"
request = Net::HTTP::Delete.new("/stamp/#{UUID}")

# Agregamos un header a la petición indicando el token que utilizaremos, en este caso el de 
# prueba 'ABCD1234'. Este debe ser modificado una vez que querramos utilizar nuestra propia cuenta
# para timbrar
request.add_field('x-auth-token', 'ABCD1234')

# Finalmente ejecutamos la petición al servidor
response = http.request(request)

# Obtenemos el codigo de respuesta del servidor y el timbre para nuestro CFD
response_code = response.code
response_message = response.body

puts "Codigo HTTP: #{response_code}"
puts "Mensaje: #{response_message}"