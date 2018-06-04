/* ==========================================================
 * Little programm for an MicroView. Basic is an Arduino UNO
 * but there is a display on it.
 * Read out temp and humidity from a DHT22 and show it
 * on two MicroViewWidgets. Also the information will be
 * shown at the serial monitor.
 * Code created by: M3taKn1ght
 * Created at:   2015/11/05 by M3taKn1ght
 * Last changes: 2015/11/14 by M3taKn1ght
 * ==========================================================
 */
//Include needed libs, see ReadMe
#include <MicroView.h>
#include <DHT.h>

//Define Pin and DHT-typ
#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

MicroViewWidget *widgetTemp;
MicroViewWidget *widgetHumi;

//Setup befor it starts
void setup() {
  Serial.begin(9600); //Init serial
  Serial.println("DHT22 - Temp and Humi!");
  dht.begin();    //init dht
  uView.begin();  //init uView
  uView.clear(PAGE);  //clear screen
  StartUp();
  /* ========================================
   * Gauge style 0 with numeric value
   * for widgetTemp a range between -20 to 80
   * for widgetHumi a range between 0 to 100
   * ========================================
   */
  widgetTemp = new MicroViewGauge(15, 24, -20, 80, WIDGETSTYLE0);
  widgetHumi = new MicroViewGauge(48, 24, 0, 100, WIDGETSTYLE0);
}

//Lets begin with the fun
void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  //Check if informations are valid
  if(isnan(t) || isnan(h) )
  {
    Serial.println("Cant't get informations from DHT22");
  }
  else
  {
    updateWidget(t, h);
    returnValuesSerial(t, h);
  }

  delay(2000);  //wait for two seconds
}

//Function to set informations for widget
void updateWidget(float temp, float humi)
{
  widgetTemp->setValue(roundValue(temp));
  widgetHumi->setValue(roundValue(humi));
  uView.display();
}

//Function to write header above the widgets
void StartUp(){
  uView.clear(PAGE);
  uView.setCursor(0, 0);
  uView.print(" Temp Humi");
  uView.display();
}

//Function to write basic information to serial monitor
void returnValuesSerial(float temp, float hum)
{
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("C");
}

//Function to round given float value
int roundValue(float value){
  double rounded = 0.0;
  if(value <= 0){
    rounded = value - 0.5;
    return (int)rounded;
  }
  else{
    rounded = value + 0.5;
    return (int)rounded;
  }
}

