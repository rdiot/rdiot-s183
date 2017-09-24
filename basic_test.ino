//For the RPI-1031 - http://www.sparkfun.com/products/10621 

int tilt_s1 = 2;
int tilt_s2 = 3;

int led_top = 8;
int led_right = 9;
int led_bottom = 10;
int led_left = 11;

void setup(){
 pinMode(tilt_s1, INPUT);
 pinMode(tilt_s2, INPUT);
 pinMode(led_top, OUTPUT);
 pinMode(led_right, OUTPUT);
 pinMode(led_bottom, OUTPUT);
 pinMode(led_left, OUTPUT);
 
 
 Serial.begin(9600);
}

void loop(){
  int position = getTiltPos();
  Serial.println(position);

  //top
  if(position == 0)
  {
    digitalWrite(led_top, HIGH); 
    digitalWrite(led_right, LOW);
    digitalWrite(led_bottom, LOW);
    digitalWrite(led_left, LOW);
  }
  //right
  else if(position == 2)
  {
    digitalWrite(led_top, LOW); 
    digitalWrite(led_right, HIGH);
    digitalWrite(led_bottom, LOW);
    digitalWrite(led_left, LOW);
  }
  //left
  else if(position == 1)
  {
    digitalWrite(led_top, LOW); 
    digitalWrite(led_right, LOW);
    digitalWrite(led_bottom, LOW);
    digitalWrite(led_left, HIGH);
  }
  //bottom
  else if(position == 3)
  {
    digitalWrite(led_top, LOW); 
    digitalWrite(led_right, LOW);
    digitalWrite(led_bottom, HIGH);
    digitalWrite(led_left, LOW);
  }
       
  delay(200); //only here to slow down the serial output
}

int getTiltPos(){
   int s1 = digitalRead(tilt_s1);
   int s2 = digitalRead(tilt_s2);
   return (s1 << 1) | s2; //bitwise math to combine the values
}
