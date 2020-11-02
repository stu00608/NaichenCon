


/*=============================Intro=============================//

EEPROM data address :

0x0 : input mode (a)Keyboard+Mouse/(b)Keyboard+Keyboard/(c)Encoder Inverse

*/
//=============================Include=============================//
#include "Encoder.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"
#include "EEPROM.h"
//=============================Define=============================//
#define DELAY 10
#define BUTTON_NUM 7
#define MODE 0
#define LIGHT 1
#define INVERSE 2

#define MODENUM 2
#define ENCODER_SENSITIVITY (double) 4
// encoder sensitivity = number of positions per rotation times 4 (400*4) / number of positions for HID report (256)

typedef struct{
  bool buttons[BUTTON_NUM];
  int xAxis,yAxis;
}State;

typedef struct{
  uint8_t btnPin;
  uint8_t ledPin;
  char data;
}Button;
//=============================Variables=============================//
Encoder encL(1,0), encR(4,3);
Button button_List[BUTTON_NUM];
State state;
Joystick_ Joystick;
uint8_t buttonPinList[BUTTON_NUM] = {7,16,14,18,21,19,10};
uint8_t joystickDataList[7] = {0,1,2,3,4,5,6};
uint8_t buttonLedList[BUTTON_NUM] = {6,8,15,5,2,20,9};
int   xAxis,xAxis_last,yAxis,yAxis_last,mode,rotate,inv;

char buttonDataList[BUTTON_NUM] = {'a','b','c','d','e','f','g'};
char EncoderToKeyboard[4] = {'h','i','j','k'};
int i;
boolean light;

//=============================Main=============================//

void setup()
{
  mode = EEPROM.read(MODE);
  
  light = EEPROM.read(LIGHT);

  inv = EEPROM.read(INVERSE);
  
  for(i=0;i<BUTTON_NUM;i++){
    button_List[i].btnPin = buttonPinList[i];
    button_List[i].ledPin = buttonLedList[i];
    pinMode(button_List[i].btnPin,INPUT_PULLUP);
    pinMode(button_List[i].ledPin,OUTPUT);
    digitalWrite(button_List[i].ledPin,LOW);
    button_List[i].data = buttonDataList[i];
  }
  if( !digitalRead(button_List[4].btnPin)&& !digitalRead(button_List[5].btnPin) ) OptionInterface();
  if(EEPROM.read(MODE)==1){
    Joystick.begin();
    Joystick.setXAxisRange(-1,1);
    Joystick.setYAxisRange(-1,1);
  }
  Keyboard.begin();
  Mouse.begin();
  
}

void loop()
{
  StateRead();
  switch(EEPROM.read(MODE)){
    case 0:
      Update_0();
      break;
    case 1:
      Update_1();
      break;
    default:
      break;
  }
    
  
  
}

//=============================Functions=============================//

void LightControl(uint8_t A,uint8_t B,uint8_t C,uint8_t D,uint8_t FX_L,uint8_t FX_R,uint8_t Start){
  digitalWrite(button_List[0].ledPin,A);
  digitalWrite(button_List[1].ledPin,B);
  digitalWrite(button_List[2].ledPin,C);
  digitalWrite(button_List[3].ledPin,D);
  digitalWrite(button_List[4].ledPin,FX_L);
  digitalWrite(button_List[5].ledPin,FX_R);
  digitalWrite(button_List[6].ledPin,Start);
  
}

int8_t rotateCheck( int now,int last ){
  int diff = abs(last-now);
  // 差超過一半則判定為255+1→0或 0-1→255的範圍
  if (diff >= 512) {
      diff = 1024-diff;
    if (now > last)
      return diff;
    return -diff;
  }
  return now-last;
}
 
void StateRead(){
  xAxis = (int)(encL.read() / ENCODER_SENSITIVITY) % 1024;
  yAxis = (int)(encR.read() / ENCODER_SENSITIVITY) % 1024;
  state.xAxis = rotateCheck(xAxis,xAxis_last);
  state.yAxis = rotateCheck(yAxis,yAxis_last);
  for(i=0;i<BUTTON_NUM;i++) state.buttons[i] = (digitalRead(button_List[i].btnPin)==LOW)? HIGH:LOW;
}

void Update_0(){
  if(inv){
    Mouse.move(state.yAxis,0,0);
    Mouse.move(0,state.xAxis,0);
  }else{
    Mouse.move(state.xAxis,0,0);
    Mouse.move(0,state.yAxis,0);
  }
  
  for(i=0;i<BUTTON_NUM;i++){
    if(state.buttons[i]){
        Keyboard.press(button_List[i].data);
        if(light) digitalWrite(button_List[i].ledPin,HIGH);
    }else{
        Keyboard.release(button_List[i].data);
        if(light) digitalWrite(button_List[i].ledPin,LOW);
    }
  }
  xAxis_last = xAxis;
  yAxis_last = yAxis;
}

void Update_1(){
  if(inv){
    Joystick.setXAxis(state.yAxis);
    Joystick.setYAxis(state.xAxis);
  }else{
    Joystick.setXAxis(state.xAxis);
    Joystick.setYAxis(state.yAxis);
  }
  
  for(i=0;i<BUTTON_NUM;i++){
    if(state.buttons[i]){
        Joystick.pressButton(joystickDataList[i]);
        if(light) digitalWrite(button_List[i].ledPin,HIGH);
    }else{
        Joystick.releaseButton(joystickDataList[i]);
        if(light) digitalWrite(button_List[i].ledPin,LOW);
    }
  }
  xAxis_last = xAxis;
  yAxis_last = yAxis;
}

void OptionInterface(){

    delay(500);
    LightControl(1,1,1,0,0,0,1);
    
    while(1){
      if(!digitalRead(button_List[0].btnPin)){
        //mode A
        mode = 0;
        LightControl(0,0,0,0,0,0,0);
        digitalWrite(button_List[mode].ledPin,HIGH);
        break;
      }else if(!digitalRead(button_List[1].btnPin)){
        //mode B
        mode = 1;
        LightControl(0,0,0,0,0,0,0);
        digitalWrite(button_List[mode].ledPin,HIGH);
        break;
      }else if(!digitalRead(button_List[2].btnPin)){
        //Encoder Inverse mode
        inv = !inv;
        LightControl(0,0,0,0,0,0,0);
        digitalWrite(button_List[2].ledPin,HIGH);
        break;
      }else if(!digitalRead(button_List[6].btnPin)){
        light = !light;
        LightControl(0,0,0,0,0,0,0);
        digitalWrite(button_List[6].ledPin,HIGH);
        break;
      }
    }
    
    EEPROM.write(MODE,mode);
    EEPROM.write(LIGHT,light);
    EEPROM.write(INVERSE,inv);
    
    delay(100);
    mode = EEPROM.read(MODE);
    light = EEPROM.read(LIGHT);
    inv = EEPROM.read(INVERSE);
    delay(1500);
    
    LightControl(0,0,0,0,0,0,0);
}
