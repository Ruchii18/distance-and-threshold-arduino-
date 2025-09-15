//this is a C++ code used in arduino 
// this code basically shows the distance of an object and the threshold from the object
int trig = 11;
int echo = 10;
int pht_sensor = A1;
int distance ;
float sign_time ;

void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {  //the trig sends the signal while the echo recieves it, when trig is high echo is low
  digitalWrite(trig, LOW);
  delay(3);
  digitalWrite(trig, HIGH);
  delay(12);
  digitalWrite(trig, LOW);
  sign_time= pulseIn( echo, HIGH); // pulseIn cals d time it takes for the signal to be recieved from the object ; for this one, its by echo
  distance = (0.034 * sign_time)/2 ; //its over 2 cus its half the total distance which is; to the object and from it
  // the ultrasonic sound speed is ideally 340 m/s but its in cm/microsecs now👌 ( pulseIn unit is in microsecs)
  Serial.print("distance in cm :");
  Serial.println(distance);
  Serial.print("threshold :");
  Serial.println(analogRead(pht_sensor));
  delay(200);
}

