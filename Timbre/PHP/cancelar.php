<?php

# Creamos una variable para guardar el el UUID del CFDI Timbrado, probablemente necesites
# cambiar este valor por un UUID valido.
$UUID = "<Agregar UUID del Timbre a Cancelar>";

# Recuerda que:
# La URL de prueba es: http://staging.diverza.com/stamp
# El token de seguridad de prueba es: ABCD1234
# El RFC emisor de prueba es: AAA010101AAA

# Creamos un arreglo para almacenar las opciones para la petición
# HTTP:
# - Se requiere utilizar el metodo HTTP DELETE
# - Agregamos el header 'x-auth-token' con el valor del token de seguridad que utilizaremos
#   en este caso 'ABCD1234'
$request_options = array(
  'http' => array(
    'method' => "DELETE",
    'header' => "x-auth-token: ABCD1234\r\n",
    'ignore_errors' => true
));

# Creamos un stream context utilizando las opciones para la peticion HTTP
$stream_context = stream_context_create($request_options);

# Ejecutamos el request a la URL del servidor de timbrado agregando el UUID del timbre a
# cancelar
$response = file_get_contents("http://staging.diverza.com/stamp/$UUID", false, $stream_context);

# Obtenemos el codigo de respuesta del servidor y el timbre para nuestro CFD
$response_code = $http_response_header[0];
$response_message = $response;

echo "Codigo HTTP: $response_code\r\n";
echo "Mensaje: $response_message\r\n";

?>