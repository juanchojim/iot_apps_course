#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>

char *ssid = "Flia victoria";
char *pass = "Victy1112ABC";

const int RST_PIN = 22;
const int SS_PIN = 21;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void scanNetworks()
{
    int numberNetworks = WiFi.scanNetworks();
    Serial.println("Redes Encontradas");
    Serial.println(numberNetworks);

    for (int i = 0; i < numberNetworks; i++)
    {
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

void connectToNetwork()
{
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Estableciendo Conexion....");
    }
    Serial.println("Conectado :D");
}

void setup()
{
    Serial.begin(115200);
    SPI.begin();
    mfrc522.PCD_Init();
    delay(6);
    mfrc522.PCD_DumpVersionToSerial();
    connectToNetwork();
    Serial.println(WiFi.localIP());
}

void loop()
{
    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return;
    }

    if (mfrc522.PICC_ReadCardSerial())
    {
        return;
    }

    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
