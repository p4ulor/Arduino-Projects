
const uint8_t lights[360]={
  0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 15, 17, 18, 20, 22, 24, 26, 28, 30, 32, 35, 37, 39,
 42, 44, 47, 49, 52, 55, 58, 60, 63, 66, 69, 72, 75, 78, 81, 85, 88, 91, 94, 97, 101, 104, 107, 111, 114, 117, 121, 124, 127, 131, 134, 137,
141, 144, 147, 150, 154, 157, 160, 163, 167, 170, 173, 176, 179, 182, 185, 188, 191, 194, 197, 200, 202, 205, 208, 210, 213, 215, 217, 220, 222, 224, 226, 229,
231, 232, 234, 236, 238, 239, 241, 242, 244, 245, 246, 248, 249, 250, 251, 251, 252, 253, 253, 254, 254, 255, 255, 255, 255, 255, 255, 255, 254, 254, 253, 253,
252, 251, 251, 250, 249, 248, 246, 245, 244, 242, 241, 239, 238, 236, 234, 232, 231, 229, 226, 224, 222, 220, 217, 215, 213, 210, 208, 205, 202, 200, 197, 194,
191, 188, 185, 182, 179, 176, 173, 170, 167, 163, 160, 157, 154, 150, 147, 144, 141, 137, 134, 131, 127, 124, 121, 117, 114, 111, 107, 104, 101, 97, 94, 91,
 88, 85, 81, 78, 75, 72, 69, 66, 63, 60, 58, 55, 52, 49, 47, 44, 42, 39, 37, 35, 32, 30, 28, 26, 24, 22, 20, 18, 17, 15, 13, 12,
 11, 9, 8, 7, 6, 5, 4, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte redpin = 3;  
const byte greenpin = 5;  
const byte bluepin = 6;  
int photoPin = A0;


int loopdelay = 500; // ms  
int displaylength = 50; // ms   

void setup() {  
  Serial.begin(9600);
}

int photoResistorV() {
  int voltageOnPhotoResistor = analogRead(photoPin);
  int roundedValue = map(voltageOnPhotoResistor, 10, 100, 0, 10);
  return roundedValue;
}


void loop() {  

  for (int red = 0; ;) {
      for (int green = 0; ; ) {
          for (int blue = 255; ;) {

            if((red<120 && red>130 | blue<120 && blue>130 ) && green!=255){ //wait on intermediary colors except green
              delay(800); 
            }

            if(blue==255 && red < 100 && red !=0){ //give more time for blue
              delay(100);
              if(red<5 && green==0){
                delay(1000);
                if(red==1){
                  delay(5000);
                }
              }
            }

            if(blue==255 && red ==0 && green==0){
              delay(5000);
            }

            if(blue==255 && green < 30 && green!=0){
                delay(300);
              }
            
            if(red==0 && blue>=255)
              green++;

            if(red==0 && green>=255)
              blue--;

            if(blue==0 && green>=255)
              red++;

            if(red>=255 && blue==0)
              green--;

            if(red>=255 && green==0)
              blue++;

            if(blue>=255 && green==0)
              red--;
            
            Serial.print(red); Serial.print(" "); Serial.print(green); Serial.print(" "); Serial.println(blue);
            if (photoResistorV() == 0) {
              analogWrite(redpin, red);  
              analogWrite(greenpin, green);  
              analogWrite(bluepin, blue+1000);
            }
      
            else {
              analogWrite(redpin, 0);
              analogWrite(greenpin, 0);
              analogWrite(bluepin, 0);
        
              while(true){
                if(photoResistorV() ==0)
                  break;
              }
            }
          }
      }
  }


  //method2
  
//  int lenght = sizeof(lights);
//  for (int k=0; k < 765; k++)  {  
//    analogWrite(redpin, lights[(k+120)%360]);  
//    analogWrite(greenpin, lights[k]);  
//    analogWrite(bluepin, lights[(k+240)%360]);  
//    
//    if (photoResistorV() == 0) {
//      
//      analogWrite(redpin, lights[(k+120)%lenght]);  
//      analogWrite(greenpin, lights[k]);  
//      analogWrite(bluepin, lights[(k+240)%lenght]);
//      
//      Serial.print(lights[(k+240)%lenght]);
//      Serial.print("at");
//      Serial.println(lights[k])
//    }
//  
//    else {
//      analogWrite(redpin, 0);
//      analogWrite(greenpin, 0);
//      analogWrite(bluepin, 0);
//
//      while(true){
//        if(photoResistorV() ==0)
//          break;
//      }
//    }
//    
//    delay(displaylength);  
//  }
//  delay(loopdelay);  
}
