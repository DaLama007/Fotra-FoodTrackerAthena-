#include <LiquidCrystal.h>

const int FoodButton = 7
const int WaterButton = 8

// init useful time vars
const int tOfHalfDay = 12*3600*1000; // in ms
const int feedtingTimePM =  

enum State{
  AM,
  PM
};

void setup(){

  // initialize buttons
  pinMode(FoodButton, INPUT);
  pinMode(WaterButton, INPUT);

  // initialize display
  lcd.begin(20, 4);
}

State st = 0;
bool gavefood = false;
bool changedWater = false;

void loop(){
  int part = millis()/tOfHalfDay%2;
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
  }
  

  //update the display with new values

  lcd.print("Athena has eaten: " + gavefood ? "Yes" : "No");
  lcd.print("Athena has new water: " + changedWater ? "Yes" : "No");
}
