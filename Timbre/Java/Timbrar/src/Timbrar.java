import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;

public class Timbrar {
	public static void main(String args[]) {
		try {
			/* Recuerda que:
       * La URL de prueba es: http://staging.diverza.com/stamp
       * El token de seguridad de prueba es: ABCD1234
       * El RFC emisor de prueba es: AAA010101AAA */
			
			/* Por facilidad leemos el CFD a timbrar del archivo cfd.xml que se encuentra
			 * en la carpeta resources */
			String cfd = new Scanner(new File("resources/cfd.xml")).useDelimiter("\\Z").next();
						
			/* Creamos una nueva instancia del objeto URL con la direcci—n del servicio de
			 * timbrado */
			URL url = new URL("http://staging.diverza.com/stamp");
			
			/* Inicializamos un nuevo objeto HttpURLConnection que nos servira para realizar
			 * la petici—n HTTP */
			HttpURLConnection connection = (HttpURLConnection)url.openConnection();
			
			// Indicamos que el methodo HTTP a utilizar es POST
			connection.setRequestMethod("POST");
			
			/* Agregamos un header a la petici—n indicando el token que utilizaremos, en este caso el de 
			 * prueba 'ABCD1234'. Este debe ser modificado una vez que querramos utilizar nuestra propia cuenta
			 * para timbrar */
			connection.setRequestProperty("x-auth-token", "ABCD1234");

			// Configuramos la conexi—n para permitirnos recibir y enviar informaci—n
			connection.setUseCaches(false);
			connection.setDoInput(true);
			connection.setDoOutput(true);

			// Utilizando una instancia de DataOutputStream enviamos el CFD a timbrar.
			DataOutputStream dataOutputStream = new DataOutputStream(connection.getOutputStream());
			dataOutputStream.writeBytes(cfd);
			dataOutputStream.flush();
			dataOutputStream.close();
			
			// Obtenemos el codigo de respuesta del servidor
			int responseCode = connection.getResponseCode();
			String responseMessage = connection.getResponseMessage();
			
			System.out.println(String.format("Codigo HTTP: %s %s", responseCode, responseMessage));

			/* Recuperamos el resultado del timbrado utilizando una instancia de InputStream y
			 * lo almacenamos en la variable stamp */
			InputStream inputStream = connection.getInputStream();
			BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
			String newLine;
			StringBuffer stamp = new StringBuffer();
			while ((newLine = bufferedReader.readLine()) != null) {
				stamp.append(newLine);
			}
			bufferedReader.close();
			
			System.out.println(String.format("Timbre: %s", stamp.toString()));
			
		} catch (IOException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
