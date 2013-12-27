#!/usr/local/bin/perl
use HTTP::Request::Common;
use LWP::UserAgent;

# Creamos una variable para guardar el el UUID del CFDI Timbrado, probablemente necesites
# cambiar este valor por un UUID valido.
$UUID = "<Agregar UUID del Timbre a Cancelar>";

# Recuerda que:
# La URL de prueba es: http://staging.diverza.com/stamp/
# El token de seguridad de prueba es: ABCD1234
# El RFC emisor de prueba es: AAA010101AAA

# Creamos una nueva instancia del objeto UserAgent
my $user_agent = new LWP::UserAgent;

# Initializamos un nuevo HTTP::Request indicando la URL del servidor de timbrado agregando
# el UUID del timbre que deseamos cancelar, el methodo DELETE de HTTP y el token de seguridad 
# que usaremos, en este caso el de prueba 'ABCD1234'. Este debe ser modificado una vez que 
# querramos utilizar nuestra propia cuenta para timbrar
my $request = new HTTP::Request DELETE => "http://staging.diverza.com/stamp/${UUID}", HTTP::Headers->new('x-auth-token' => 'ABCD1234');

# El CFD a timbrar debe ser agregado como cuerpo de la petición
$request->content($cfd);

# Finalmente ejecutamos la petición al servidor
my $response = $user_agent->request($request); 

# Obtenemos el codigo de respuesta del servidor y el timbre para nuestro CFD
my $response_code = $response->status_line;
my $response_message = $response->decoded_content;

print "Codigo HTTP: ${response_code}\n";
print "Mensaje: ${response_message}\n";