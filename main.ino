#include <LiquidCrystal.h>

const int FoodButton = 7;
const int WaterButton = 8;

// init useful time vars
const int tOfHalfDay = 12*3600*1000; // in ms

enum State{
  AM,
  PM
};

void setup(){

  // initialize buttons
  pinMode(FoodButton, INPUT);
  pinMode(WaterButton, INPUT);

  // initialize display
  lcd = 
  lcd.begin(20, 4);
}

State state = AM;
bool gavefood = false;
bool changedWater = false;

void loop(){
  long long part = millis()/tOfHalfDay%2;
  FoodButtonState = digitalRead(FoodButton);
  WaterButtonState = digitalRead(WaterButton);
  switch(state){
    case AM:
      if(part==1){
        state = PM;
        gavefood = false;
      }
      else{

        //check button presses
        if(FoodButtonState == HIGH) gavefood = true;
        if(WaterButtonState == HIGH) changedWater = true;
      }
      break;
    case PM:
      if(part==0){
        state = AM;
        gavefood = false;
        changedWater = false;
      }
      else{
        //check button presses
        if(FoodButtonState == HIGH) gavefood = true;
        if(WaterButtonState == HIGH) changedWater = true;
      }
      break;
  }
  

  //update the display with new values
  lcd.setCursor(0, 0);
  string test1 = "Athena has eaten: " + (gavefood ? "Yes" : "No");
  lcd.print(test1);
  lcd.setCursor(0, 2);
  string test2 = "Athena has new water: " + (changedWater ? "Yes" : "No");
  lcd.print(test2);
}
