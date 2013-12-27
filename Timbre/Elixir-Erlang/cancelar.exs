# Creamos una variable para guardar el el UUID del CFDI Timbrado, probablemente necesites
# cambiar este valor por un UUID valido.
uuid = '<Agregar UUID del Timbre a Cancelar>'

# Recuerda que:
# La URL de prueba es: http://staging.diverza.com/stamp
# El token de seguridad de prueba es: ABCD1234
# El RFC emisor de prueba es: AAA010101AAA

# Guardamos la URL del servidor de timbrado en la variable url agregandole el UUID del CFDI a 
# cancelar
url = 'http://staging.diverza.com/stamp/#{uuid}'

# Creamos una lista con el header que enviaremos en la petición indicando el token que utilizaremos, 
# en este caso el de prueba 'ABCD1234'. Este debe ser modificado una vez que querramos utilizar nuestra 
# propia cuenta para timbrar
headers = [{ 'x-auth-token', 'ABCD1234' }]

# Iniciamos el actor inets, necesario para ejecutar la petición HTTP
:inets.start

# Finalmente ejecutamos la petición enviando la url y los headers
{ :ok, { { _, http_code, _ }, _, response_message } } = :httpc.request(:delete, { url, headers, 'application/xml', '' }, [], [])

IO.puts "Codigo HTTP: #{http_code}"
IO.puts "Mensaje: #{response_message}"

# Detenemos el actor inets
:inets.stop