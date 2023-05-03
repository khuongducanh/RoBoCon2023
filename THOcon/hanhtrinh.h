 void Hanhtrinh(){
   Goilaibien();
  //reser lồng
   if(DemL2 == 0 && b2 == 1 &&( b1 == 1 || b1 == 0)){
      digitalWrite(DIR5,HIGH);
      analogWrite(PWM5,pwm(20));
   }
   else if(b2 == 0 && DemL2 == 0){
     analogWrite(PWM5,pwm(0));
   }
  //hạ lồng vòng 
   if(DemL2 == 1 && b2 == 0 && b1 == 1){
     digitalWrite(DIR5,LOW);
     analogWrite(PWM5,pwm(20));
   }
   else if(b1 == 0 && b2 == 1 && DemL2 == 1){
     analogWrite(PWM5,pwm(0));
   }
  // nâng lồng vòng 
   if(DemL2 == 2 && (b1 == 0 || b1 == 1) && b2 == 1 && tiemcan1 == 1){
     digitalWrite(DIR5,HIGH);
     analogWrite(PWM5,pwm(20));
     analogWrite(PWM7,pwm(141));
   }
   if((tiemcan1 == 0 && DemL2 == 2) || R1){
     analogWrite(PWM5,pwm(0));
   }

   if(b2 == 0 && DemL2 == 2 && b1 == 1){
     analogWrite(PWM5,pwm(0));
   }
 }




