/*
    UCR Solar Tracker
    Made by: Kishen Nadasia and Jonathan Chiem
*/

#include <Stepper.h>

int x = 0;   // this counts the x axis meaning the position of the first motor
int temp_x = 0;
int y = 0;  // this counts the y axis meaning the position of the second motor
int temp_y = 0;
int num_steps = 512;
Stepper stepperRotate(num_steps, 8, 10, 9, 11);
Stepper stepperTilt(num_steps, 3, 5, 4, 6);

void setup() {
  Serial.begin(9600); //enables sensor readings to the serial monitor
}

void loop() {
  int one = analogRead(A0);     // set them to their particular pin they are connected to 
  int two = analogRead(A1);    //      1     3
  int three = analogRead(A2); //       2     4
  int four = analogRead(A3); // one thru four are the different photoresisters. orientation is above
  
  Serial.print(one);
  Serial.print("\t");
  Serial.print(two);
  Serial.print("\t");
  Serial.print(three);
  Serial.print("\t");
  Serial.print(four);
  Serial.print("\t");
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.println();  
  
  if ((one > 900) && (two > 900) && (three > 900) && (four > 900)) {  //if all values are the same return 
      if (x > 0){                                                     //to initial position (sun is above the panel)
        for(int i = 0; i < x; i++) {                                  
          step_tilt(-1);
          delay(10);
        }
      }
      if(x < 0){
        temp_x = abs(x);
        for(int i = 0; i < temp_x; i++) {
            step_tilt(1);
            delay(10);
        }
      }
      if (y > 0){
        for(int i = 0; i < y; i++) {
          step_rotate(-1);
          delay(10);
        }
      }
      if(y < 0){
        temp_y = abs(y);
        for(int i = 0; i < temp_y; i++) {
          step_rotate(1);
          delay(10);
        }
      }
  }
  
  if ((one > two) && (one > three) && (one > four)) {  // if it is closer to 1
    if(one > 915) {
      step_tilt(1);
      step_rotate(-1);
      delay(10);
    }
  }
  if ((two > one) && (two > three) && (two > four)) {   // if it is closer to 2
    if(two > 915) {
      step_tilt(-1);
      step_rotate(-1);
      delay(10);
    }
  }
  if ((three > one) && (three > two) && (three > four)) {  // if it is closer to 3
    if(three > 915) {
      step_tilt(1);
      step_rotate(1);
      delay(10);
    }
  }
  if ((four > one) && (four > two) && (four > three)) {   // if it is closer to 4
    if(four > 915) {
      step_tilt(-1);
      step_rotate(1);
      delay(10);
    }
  }
}
  
void step_tilt(int x_val) { //tilts solar panel and checks tilt position
 if(x == 128) {
  if (x_val < 0){
    stepperTilt.step(x_val);
    --x;
  }
 }
 if(x == -128) {
  if (x_val > 0){
    stepperTilt.step(x_val);
    ++x;
  }
 }
 if ((x < 128) && (x > -128)) {
  stepperTilt.step(x_val);
  if (x_val < 0){
    --x;
  }
  if(x_val > 0){
    ++x;
  }
 }
}

void step_rotate(int y_val) { // rotates solar panel and checks rotate position
  if(y == 256) {
    if (y_val < 0){
      stepperRotate.step(y_val);
      --y;
    }
  }
  if(y == -256) {
    if (y_val > 0){
      stepperRotate.step(y_val);
      ++y;
    }
  }
 if ((y < 256) && (y > -256)) {
  stepperRotate.step(y_val);
  if(y_val < 0) {
    --y;
  }
  if(y_val > 0) {
    ++y;
  } 
 }
}
