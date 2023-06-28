#include <SimpleDHT.h>
int sensorIn = 4;
int relaiControllOut = 3;

SimpleDHT11 dht11(sensorIn);

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
    pinMode(relaiControllOut, OUTPUT);
    digitalWrite(relaiControllOut, LOW);
}
void loop()
{
    float erg = checkTemp();
    Serial.println(erg);
    if (erg > 26)
    {
        digitalWrite(relaiControllOut, HIGH);
    }
    else
    {
        digitalWrite(relaiControllOut, LOW);
    }
    delay(1500);
}