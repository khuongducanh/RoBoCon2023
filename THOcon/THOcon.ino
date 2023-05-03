#include <LiquidCrystal.h>
#include <PS2X_lib.h>  
#include"Khaibaobien.h"
#include"LCD.h"
#include"linhtinh.h"
#include"dongcoban.h"
#include"Move.h"  
#include"hanhtrinh.h"
void setup(){
  Serial.begin(57600);
  lcd.begin(20, 4);
  #include "INandOUT.h"
}
void loop(){
  if(error == 1 ) return;
  else{
      Goilaibien();
      ps2x.read_gamepad(false, vibrate);
    if(L1){
        Speed();                      //tangtoc
        Nangvong(phaidoc,phaingang);  //nang long
         }
  //**************************************
  else{ 
        Goilaibien();
        ps2x.read_gamepad(false, vibrate);
        //DemL1
        while(L2){
        DemL2++;
        while(L2){
        Goilaibien();
          }
        }
      //Demselect
        while(select){
        DemSelect++;
        while(select){
        Goilaibien();
        if(select && DemSelect > 0){ 
          DemL2  = 0 ;
              }
            }
          }
        Resetboard(L3 && R3);  //Reset Board Arduino
        dkdongco();      //dk dong co
        Move();          //binhthuong
        Hanhtrinh();     //nangvong  
        Check();         //kiemtra cong tac 
        Dcmoc(R1,R2);    //dongcomocvong
      /*
        Serial.println(traidoc);
        Serial.println(traingang); 
        Serial.println(phaidoc);
        Serial.println(phaingang);*/
      
    }
  }
}
