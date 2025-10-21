#include <DHT.h>
#include <LiquidCrystal.h>

#define DHT_SENSOR_PIN 2
#define DHT_SENSOR_TYPE DHT11
#define BUTTON_PIN 7
#define ENABLE_PIN 5
#define DIRA_PIN 3
#define DIRB_PIN 4 

DHT dht(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); 

boolean fan_on = false;
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    
bool lastButtonState = HIGH;         
bool currentButtonState = HIGH;      

float temperature = 0.0;
float humidity = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  pinMode(ENABLE_PIN, OUTPUT);       
  pinMode(DIRA_PIN, OUTPUT);         
  pinMode(DIRB_PIN, OUTPUT);         
  lcd.begin(16, 2);                 
  lcd.print("Fan Control");
  delay(1000);                       
  dht.begin();                      
}

void loop() {
 
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.print("Error reading DHT");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  if (temperature > 25.0 && !fan_on) {
    digitalWrite(ENABLE_PIN, HIGH); // turn fan ON if temperature > 25°C
    fan_on = true;
    digitalWrite(DIRA_PIN, HIGH);
    Serial.println("Fan ON: Temperature > 25°C");
  } else if (temperature <= 25.0 && fan_on) {
    digitalWrite(ENABLE_PIN, LOW);  // turn fan OFF if temperature <= 25°C
    fan_on = false;
    digitalWrite(DIRA_PIN, LOW);
    Serial.println("Fan OFF: Temperature <= 25°C");
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();  
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (currentButtonState == LOW) { 
     
      fan_on = false;
      digitalWrite(ENABLE_PIN, LOW); 
      digitalWrite(DIRA_PIN, LOW);  
      Serial.println("Button pressed! Fan reset to OFF.");
    }
  }

  lastButtonState = currentButtonState;

  Serial.print("Fan State: ");
  Serial.println(fan_on ? "ON" : "OFF");

  delay(500);
}
