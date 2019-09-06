#include <ESP8266WiFi.h>


const char* ssid="Juan";
const char* password="12345" ; 

WiFiServer server(80);


void setup() {
  Serial.begin(115200);
  Serial.println("Configurando AP....");

  WiFi.softAP(ssid,password);
  IPAddress myIP= WiFi.softAPIP();
  Serial.print("http://");
  Serial.println(myIP);

  server.begin();
  Serial.print("Servidor Iniciado....");
  
}

void loop() {
  WiFiClient client = server.available();
  
  if(!client){
    return; 
  }

  Serial.print("Creando Nuevo Cliente");
  Serial.println(client.remoteIP());

  while(!client.available()){
    delay(1);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("HTTP/1.1 200 OK");
  client.println("");
  client.println("<DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta charset=utf-8></head>");
  client.println("<body>");
   client.println("<h1>Hola soy una esp8266</h1>");
  client.println("</body>");
  client.println("</html>");
  
  
}
