void dichuyen(int d1 ,int d2 ,int d3,int d4, int xungA,int xungB,int xungC,int xungD){
  digitalWrite(DIR1,d1);analogWrite(PWM1,pwm(xungA));
  digitalWrite(DIR2,d2);analogWrite(PWM2,pwm(xungB));
  digitalWrite(DIR3,d3);analogWrite(PWM3,pwm(xungC));
  digitalWrite(DIR4,d4);analogWrite(PWM4,pwm(xungD));
}
void tien  (int x){if(up    && !down && !right && !left  && !pink && !red) {Goilaibien();inralcd("Tien  ");dichuyen(HIGH,LOW,LOW,HIGH,x,x,x,x);}}
void lui   (int x){if(down  && !up   && !right && !left  && !pink && !red) {Goilaibien();inralcd("Lui   ") ;dichuyen(LOW,HIGH,HIGH,LOW,x,x,x,x);}}
void trai  (int x){if(left  && !up   && !down  && !right && !pink && !red) {Goilaibien();inralcd("Trai ");dichuyen(LOW,LOW,HIGH,HIGH ,x,x,x,x);}}
void phai  (int x){if(right && !up   && !down  && !left  && !pink && !red) {Goilaibien();inralcd("Phai ");dichuyen(HIGH,HIGH,LOW,LOW,x,x,x,x);}}
/*
void cheor (int x){if(traingang ==  1023 && traidoc<-30 && traidoc>-950 && !L1 && !R1){inralcd("CPhai");dichuyen(HIGH,LOW ,LOW, HIGH,x,0,x,0);}}
void cheol (int x){if(traingang == -1023 && traidoc<-30 && traidoc>-950 && !L1 && !R1){inralcd("CTrai");dichuyen(HIGH,LOW ,LOW, HIGH,0,x,0,x);}}
void cheodl(int x){if(traingang == -1023 && traidoc>30  && traidoc< 950 && !L1 && !R1){inralcd("TraiD");dichuyen(LOW,LOW ,HIGH, HIGH,x,0,x,0);}}
void cheodr(int x){if(traingang ==  1023 && traidoc>30  && traidoc< 950 && !L1 && !R1) {inralcd("PhaiD");dichuyen(LOW,HIGH,HIGH, LOW ,0,x,0,x);}}*/

void xoayl(int x){if(pink && !up && !down && !right && !left && !red)   {inralcd("xtrai");dichuyen(LOW ,LOW ,LOW ,LOW  ,x,x,x,x);}}
void xoayr(int x){if(red  && !up && !down && !right && !left && !pink)  {inralcd("xphai");dichuyen(HIGH,HIGH,HIGH,HIGH ,x,x,x,x);}}
void dung()      {if(!up  && !down && !right && !left && !red && !pink) {inralcd("Stop"); dichuyen(HIGH,HIGH ,HIGH,HIGH,0,0,0,0);}}

void Speed(){
  Goilaibien();
  int max = 45 ;
  tien  (max); lui (max);
  trai  (max); phai(max);
  /*cheor (max);cheol(max);
  cheodl(max);cheodr(max);*/
  dung();
}

void Move(){
  Goilaibien();
  int binhthuong = 25;
  int liti       = 15 ;
  tien(binhthuong)  ;lui(binhthuong);
  trai(binhthuong)  ;phai(binhthuong);
  // cheor(binhthuong) ;cheol(binhthuong);
  // cheodl(binhthuong);cheodr(binhthuong);
  xoayl(liti);xoayr(liti);
  dung();
}