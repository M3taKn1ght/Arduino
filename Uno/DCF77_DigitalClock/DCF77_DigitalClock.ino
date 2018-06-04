#include <Time.h>
#include <TimeLib.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DCF77.h>


#define DCF_PIN 2
#define DCF_INTERRUPT 0

DCF77 DCF = DCF77(DCF_PIN, DCF_INTERRUPT);
bool initTime;
LiquidCrystal_I2C lcd(0x27,16,2);
time_t NextSyncTime;
int WaitTime;
int LastMinute;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  initTime = true;
  WaitTime = 0;
  NextSyncTime = 0;
  Serial.begin(9600); 
  Serial.println("1   - binary 1 corresponding to long pulse");
  Serial.println("0   - binary 0 corresponding to short pulse");
  Serial.println("BF  - Buffer is full at end of time-sequence. This is good");
  Serial.println("EoB - Buffer is full before at end of time-sequence");
  Serial.println("EoM - Buffer is not yet full at end of time-sequence");
  DCF.Start();
  lcd.backlight();
  lcd.clear();
  lcd.home();
  lcd.print("DCF77-Clock");
  lcd.setCursor(0,1);
  lcd.print("(c) M3taKn1ght");
  delay(5000);
  LastMinute = -1;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(initTime)
  {
    lcd.clear();
    lcd.home();
    lcd.print("Init DCF77-time");
    lcd.setCursor(0,1);
    lcd.print("Please wait");
    delay(1000);
    time_t DCFtime = DCF.getTime();
    time_t DCFutc = DCF.getUTCTime();
    if(DCFtime != 0)
    {
      setNewTime(DCFtime);
      initTime = false;
      WaitTime = 0;
    }
    else
    {
      WaitTime+=5;
      Serial.print("Waited ");
      Serial.print(WaitTime);
      Serial.println(" second(s)");
    }
    delay(5000);
  }
  else
  {
    time_t t = now();
    Serial.print("Diff: ");
    int result = t - NextSyncTime;
    Serial.print(result);
    Serial.println("");
    if(result > 3600)
    {
       time_t DCFtime = DCF.getTime();
       if(DCFtime != 0)
      {
        setNewTime(DCFtime);
      }
    }
    if(LastMinute != minute(t))
    {
      LastMinute = minute(t);
      tmElements_t tm_Element;
      breakTime(t, tm_Element);
      ShowNewTime(tm_Element);
    }
    delay(1000);   
  }

}

void setNewTime(time_t _time)
{
  tmElements_t tm;
  breakTime(_time, tm);
  NextSyncTime = _time;
  setTime(_time);
  NextSyncTime = now();
}

void printDigitsSerial(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void printDigitsLCD(int digits){
  if(digits < 10)
    lcd.print("0");
   lcd.print(digits);
}

void ShowNewTime(tmElements_t _tm)
{
  //Write to SerialMonitor
  Serial.println("");
  Serial.print("Time: ");
  Serial.print(_tm.Hour);
  Serial.print(":");
  printDigitsSerial(_tm.Minute);
  Serial.print(":");
  printDigitsSerial(_tm.Second);
  Serial.println("");
  Serial.print("Date: ");
  printDigitsSerial(_tm.Day);
  Serial.print(".");
  printDigitsSerial(_tm.Month);
  Serial.print(".");
  Serial.println(_tm.Year+1970);
  Serial.println("");

  //Write to display
  lcd.clear();
  lcd.home();
  lcd.print("Time: ");
  lcd.print(_tm.Hour);
  lcd.print(":");
  printDigitsLCD(_tm.Minute);
  lcd.setCursor(0,1);
  lcd.print("Date: ");
  printDigitsLCD(_tm.Day);
  lcd.print(".");
  printDigitsLCD(_tm.Month);
  lcd.print(".");
  lcd.print(_tm.Year+1970);
}

