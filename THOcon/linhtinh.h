void Goilaibien(){
  ps2x.read_gamepad();
  ps2x.read_gamepad(false, vibrate);
  //gan bien cho nut nhan////////////////////////////////////////////////
  up        = ps2x.Button(PSB_PAD_UP);                                 // 
  down      = ps2x.Button(PSB_PAD_DOWN);                              //   
  right     = ps2x.Button(PSB_PAD_RIGHT);                            //
  left      = ps2x.Button(PSB_PAD_LEFT);                            //
  L1        = ps2x.Button(PSB_L1);                                 //
  R1        = ps2x.Button(PSB_R1);                                // 
  L2        = ps2x.Button(PSB_L2);                               //
  R2        = ps2x.Button(PSB_R2);                              //
  R3        = ps2x.Button(PSB_R3);                             //
  L3        = ps2x.Button(PSB_L3);                            //
  pink      = ps2x.Button(PSB_PINK);                         // 
  red       = ps2x.Button(PSB_RED);                         //biến cục bộ 
  green     = ps2x.Button(PSB_GREEN);                      //
  blue      = ps2x.Button(PSB_BLUE);                      //
  traidoc   = ps2x.Analog(PSS_LY);                       //  
  traingang = ps2x.Analog(PSS_LX);                      //
  phaidoc   = ps2x.Analog(PSS_RY);                     //
  phaingang = ps2x.Analog(PSS_RX);                    //
  start     = ps2x.Button(PSB_START);                //
  select    = ps2x.Button(PSB_SELECT);              //  
  traidoc   = map(traidoc  ,0,255,-1023,1023);     //
  traingang = map(traingang,0,255,-1023,1023);    //
  phaidoc   = map(phaidoc  ,0,255,-1023,1023);   //
  phaingang = map(phaingang,0,255,-1023,1023);  //
/////////////////////////////////////////////////                        
    b1 = digitalRead(HT1);              //
    b2 = digitalRead(HT2);             //
    b3 = digitalRead(HT3);            // biến toàn cục
    b4 = digitalRead(HT4);           //
    b5 = digitalRead(HT5);          //
    b6 = digitalRead(HT6);         //
    tiemcan1 = digitalRead(A0);   //
    tiemcan2 = digitalRead(A1);  //
    nutlcd1 = digitalRead(37);  //
    nutlcd2 = digitalRead(35);
    delay(10); //           //
}//////////////////////////////
//check công tắc hành trình , cảm biến , 2 nút trên lcd *//
void Check(){
  Goilaibien();
  //in ra lcd cong tac hanh trinh
  if(b1 == 0){Serial.println("ct1");lcd.setCursor(14,0);lcd.print("1");}
  if(b2 == 0){Serial.println("ct2");lcd.setCursor(15,0);lcd.print("1");}
  if(b3 == 0){Serial.println("ct3");lcd.setCursor(16,0);lcd.print("1");}
  if(b4 == 0){Serial.println("ct4");lcd.setCursor(17,0);lcd.print("1");}
  if(b5 == 0){Serial.println("ct5");lcd.setCursor(18,0);lcd.print("1");}
  if(b6 == 0){Serial.println("ct6");lcd.setCursor(19,0);lcd.print("1");}
 //in ra lcd tiem can
  if(tiemcan1 == 0){Serial.println("tiemcan1");lcd.setCursor(14,1);lcd.print("1");}
  if(tiemcan2 == 0){Serial.println("tiemcan2");lcd.setCursor(15,1);lcd.print("1");}

  /*if(nutlcd1 ==0 ){Serial.println("lcd1");lcd.setCursor(15,1);lcd.print("lcd1");}
  if(nutlcd2 ==0 ){Serial.println("lcd2");lcd.setCursor(15,1);lcd.print("lcd2");}*/

  }
//****************reset board***********************//
void(* resetFunc) (void) = 0;//cài đặt hàm reset
void Resetboard(int b ){
  if(b){
    resetFunc();//tiến hành reset
  }
}
//******************nanglong***************************//
void Nangvong(int y , int x){
  if(y >= -1023 && y <-200 && x == 4){
    digitalWrite(DIR5,HIGH);
    analogWrite(PWM5,pwm(20));
  }
  if(y <= 1023 && y > 200 && x == 4){
    digitalWrite(DIR5,LOW);
    analogWrite(PWM5,pwm(20));
  }
  if(y == -5 && x == 4){
    analogWrite(PWM5,pwm(0));
  }
}
//****************dcmoc*********************************//
void Dcmoc(int x , int y) {
  Goilaibien();
  if(x){
   digitalWrite(DIR6,HIGH);
   analogWrite(PWM6,pwm(20));  
  }
  else if(y){
   analogWrite(PWM6,pwm(0));
  }
}

