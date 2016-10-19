void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600); // setup serial

  // For the positive pulse
  // T1 is high and T4 is high
  pinMode(T1pin, OUTPUT);      // sets the digital pin 3 as output
  pinMode(T2pin, OUTPUT);      // sets the digital pin 5 as output

  // Initialize DAC pins 
  pinMode(DAC0, OUTPUT);   // initialize DAC pin as an output to transistor T3.
  pinMode(DAC1, OUTPUT);   // initialize DAC pin as an output to transistor T4.   
}

void loop() {

  digitalWrite(DAC0, LOW);   // PWM to T1 transistor
  digitalWrite(DAC1, LOW);   // PWM to T1 transistor

  // put your main code here, to run repeatedly:
  digitalWrite(T1pin, LOW);   // PWM to T1 transistor
  digitalWrite(T2pin, LOW);   // PWM to T1 transistor

analogWriteResolution(12);
   
  // Sine wave into T4
  for(int i = 0; i<=255;i++){
    analogWrite(DAC1, sine[i] / 2 + 2048 );
    delayMicroseconds(19);
  }
  
  for(int i = 0; i<=255;i++){
    analogWrite(DAC1, 2048 -sine[i] / 2);
    delayMicroseconds(19);
  }

}


