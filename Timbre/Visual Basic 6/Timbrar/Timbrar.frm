VERSION 5.00
Begin VB.Form main 
   Caption         =   "Timbrar"
   ClientHeight    =   3015
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4560
   LinkTopic       =   "Form1"
   ScaleHeight     =   3015
   ScaleWidth      =   4560
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton cancela 
      Caption         =   "Cancela"
      Height          =   1095
      Left            =   120
      TabIndex        =   1
      Top             =   1680
      Width           =   4335
   End
   Begin VB.CommandButton timbra 
      Caption         =   "Timbra"
      Height          =   1095
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   4335
   End
End
Attribute VB_Name = "main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub timbra_Click()
 Dim url As String
 Dim cfd As String
 Dim responseCode As Integer
 Dim stamp As String
 Dim xmlhttp As MSXML2.xmlhttp
 
 ' Recuerda que:
 ' La URL de prueba es: http://213.239.207.18:4444/stamp
 ' El token de seguridad de prueba es: abc
 ' El RFC emisor de prueba es: AAA010101AAA
 ' El certificado de prueba lo puedes descargar de: ----LLENAR-----

 ' Por facilidad leemos el CFD a timbrar del archivo cfd.xml que se
 ' encuentra en la misma carpeta del proyecto
 cfdFile = FreeFile
 Open App.Path + "\cfd.xml" For Input As cfdFile
 cfd = Input(LOF(cfdFile), cfdFile)
 Close cfdFile

 ' Inicializamos un nuevo objeto HttpURLConnection que nos servira para
 ' realizar la petición HTTP
 Set xmlhttp = New xmlhttp
 url = "http://213.239.207.18:4444/stamp"

 ' Abrimos la conexión al servicio de timbrado utilizando el metodo post,
 ' de HTTP y la URL
 xmlhttp.Open "POST", url, False
 
 ' Agregamos un header a la petición indicando el token que utilizaremos,
 ' en este caso el de prueba 'abc'. Este debe ser modificado una vez que
 ' querramos utilizar nuestra propia cuenta para timbrar
 xmlhttp.setRequestHeader "x-auth-token", "abc"
 
 ' Enviarmos el CFD a timbrar como cuerpo de la petición.
 xmlhttp.send cfd

 ' Obtenemos el codigo de respuesta del servidor y el timbre para nuestro
 ' CFD
 responseCode = xmlhttp.Status
 stamp = xmlhttp.responseText
 
 MsgBox "Codigo HTTP: " + Str(responseCode)
 MsgBox "Timbre: " + stamp
End Sub
