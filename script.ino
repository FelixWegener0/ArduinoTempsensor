#include <SimpleDHT.h>
int pinDHT11 = 4;
SimpleDHT11 dht11(pinDHT11);

float checkTemp()
{
    float temperature = 0;
    float humidity = 0;
    int err = SimpleDHTErrSuccess;
    if ((err = dht11.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
    {
        Serial.print("Read DHT11 failed, err=");
        Serial.println(err);
        delay(2000);
        return;
    }
    return temperature;
}

void setup()
{
    Serial.begin(115200);
    pinMode(3, OUTPUT);
    digitalWrite(3, LOW);
}
void loop()
{
    float erg = checkTemp();
    Serial.println(erg);
    if (erg > 26)
    {
        digitalWrite(3, HIGH);
    }
    else
    {
        digitalWrite(3, LOW);
    }
    delay(1500);
}