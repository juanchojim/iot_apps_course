#include <ESP8266WiFi.h> 


 char* ssid="Flia victoria"; 
 char* pass ="Victy1112ABC";

void scanNetworks(){
   int numberNetworks = WiFi.scanNetworks(); 
   Serial.println("Redes Encontradas");
   Serial.println(numberNetworks);

   for(int i=0; i<numberNetworks;i++){
    Serial.println("Nombre: ");
    Serial.println(WiFi.SSID(i));

    Serial.println("Intensidad: ");
    Serial.println(WiFi.RSSI(i));
  
    Serial.println("MAC: ");
    Serial.println(WiFi.BSSIDstr(i));

    Serial.println("Encriptación: ");
    Serial.println(WiFi.encryptionType(i));

    Serial.println("================");
   }
}


void connectToNetwork(){
  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Estableciendo Conexion....");
  }
  Serial.println("Conectado :D");
}


void setup() {
 Serial.begin(115200); 
 scanNetworks(); 
 connectToNetwork(); 
 Serial.println(WiFi.localIP());
}

void loop() {

}
