package main

import (
  "net/http"
  "io/ioutil"
  "fmt"
)

func main() {

  /* Creamos una variable para guardar el el UUID del CFDI Timbrado, probablemente necesites
  // cambiar este valor por un UUID valido. */
  UUID := "<Agregar UUID del Timbre a Cancelar>"

  /* Recuerda que:
   * La URL de prueba es: http://staging.diverza.com/stamp
   * El token de seguridad de prueba es: ABCD1234
   * El RFC emisor de prueba es: AAA010101AAA */

  // Usaremos una instancia de client para realizar la petición al servidor de timbrado
  client := &http.Client{}

  /* Creamos un nuevo request indicando que usaremos el metodo DELETE de HTTP y la URL del
   * servidor de timbrado agregando el UUID del CFDI a cancelar */
  request, _ := http.NewRequest("DELETE", fmt.Sprint("http://staging.diverza.com/stamp/", UUID), nil)

  /* Agregamos un header a la petición indicando el token que utilizaremos, en este caso el de 
   * prueba 'ABCD1234'. Este debe ser modificado una vez que querramos utilizar nuestra propia cuenta
   * para timbrar */
  request.Header.Add("x-auth-token", "ABCD1234")

  // Finalmente ejecutamos la petición al servidor
  response, _ := client.Do(request)
  defer response.Body.Close()

  // Obtenemos el codigo de respuesta del servidor y el timbre para nuestro CFD
  stamp, _ := ioutil.ReadAll(response.Body)
  responseCode := response.Status

  fmt.Println("Codigo HTTP:", responseCode)
  fmt.Println("Timbre:", string(stamp))
}