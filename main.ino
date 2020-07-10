// juste la partie de récupération qui concerne le capteur de CO2, Température et Humidité
#include "DHT.h"   // Librairie des capteurs DHT

#define DHTPIN 2    // Changer le pin sur lequel est branché le DHT

// Dé-commentez la ligne qui correspond à votre capteur 
#define DHTTYPE DHT22       // DHT 22
const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;
DHT dht(DHTPIN, DHTTYPE); 
void setup() {
  Serial.begin(9600); 
  dht.begin();

  Serial.begin(115200);//sets the baud rate
  pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
  pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
}

void loop() {
  delay(12121);

  // Lecture du taux d'humidité
  float h = dht.readHumidity();
  // Lecture de la température en Celcius
  float t = dht.readTemperature();
  // Pour lire la température en Fahrenheit
  float f = dht.readTemperature(true);
  
  // Stop le programme et renvoie un message d'erreur si le capteur ne renvoie aucune mesure
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Echec de lecture !");
    return;
  }

  Serial.print("Humidite: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C ");

  // envoie des valeur pour lhumidite et temperature au gateway(not implemented yet) (Localhost:5000/create)
  

    alue= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
    limit= digitalRead(DOUTpin);//reads the digital value from the CO sensor's DOUT pin
    Serial.print("CO value: ");
    Serial.println(value);//prints the CO value
    Serial.print("Limit: ");
    Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
    delay(100);
    if (limit == HIGH){
    digitalWrite(ledPin, HIGH);//if limit has been reached, LED turns on as status indicator
    }
    else{
    digitalWrite(ledPin, LOW);//if threshold not reached, LED remains off
    }
  // envoie des valeur pour CO2 au gateway(not implemented yet)  (Localhost:5000/create)

}