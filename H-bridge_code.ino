// The following code programs the output stage's H-bridge circuit schematic. There are two ways of producing the biphasic signal. Both are written here. 
// Author: Imraan Dean
// Set the PWM pin for top two transistors
int T1pin = 3;
int T2pin = 5;

// Variable to store value of analog pin
int val = 0;

// Sine wave lookup table
int sine[] = 
  // Sine wave
  {0,50,101,151,202,252,302,353,403,453,503,553,603,653,703,752,802,851,901,950,999,1048,1096,1145,1193,1241,
  1289,1337,1385,1432,1479,1526,1573,1619,1666,1712,1757,1803,1848,1893,1937,1982,2026,2069,2113,2156,2198,2241,
  2283,2325,2366,2407,2448,2488,2528,2567,2606,2645,2683,2721,2759,2796,2833,2869,2905,2940,2975,3009,3043,3077,
  3110,3142,3174,3206,3237,3268,3298,3328,3357,3385,3414,3441,3468,3495,3521,3546,3571,3596,3620,3643,3666,3688,
  3710,3731,3751,3771,3790,3809,3828,3845,3862,3879,3895,3910,3925,3939,3952,3965,3977,3989,4000,4011,4021,4030,
  4038,4047,4054,4061,4067,4073,4078,4082,4086,4089,4091,4093,4094,4095,4095,4094,4093,4091,4089,4086,4082,4078,
  4073,4067,4061,4054,4047,4038,4030,4021,4011,4000,3989,3977,3965,3952,3939,3925,3910,3895,3879,3862,3845,3828,3809,3790,3771,3751,3731,3710,3688,3666,3643,3620,3596,3571,3546,3521,3495,3468,3441,3414,3385,3357,3328,3298,3268,3237,3206,3174,3142,3110,3077,3043,3009,2975,2940,2905,2869,2833,2796,2759,2721,2683,2645,2606,2567,2528,2488,2448,2407,2366,2325,2283,2241,2198,2156,2113,2069,2026,1982,1937,1893,1848,1803,1757,1712,1666,1619,1573,1526,1479,1432,1385,1337,1289,1241,1193,1145,1096,1048,999,950,901,851,802,752,703,653,603,553,503,453,403,353,302,252,202,151,101,50,0
  };


// Method 1 of producing biphasic pulse using only the Arduino's PWM:
// the setup routine runs once when you press reset:
void setup() 
{ 

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
  
  // put your main code here, to run repeatedly:
  digitalWrite(DAC0, LOW);   // PWM to T3 transistor
  digitalWrite(DAC1, LOW);   // PWM to T4 transistor

  
  digitalWrite(T1pin, HIGH);   // PWM to T1 transistor
  digitalWrite(T2pin, LOW);   // PWM to T2 transistor

analogWriteResolution(12);
   
  // Sine wave into T4
  for(int i = 0; i<=255;i++){
    analogWrite(DAC1, sine[i]);
    delayMicroseconds(19);
  }
  
  digitalWrite(DAC0, LOW);   // PWM to T3 transistor
  digitalWrite(DAC1, LOW);   // PWM to T4 transistor


  digitalWrite(T1pin, LOW);   // PWM to T1  transistor
  digitalWrite(T2pin, HIGH);   // PWM to T2 transistor

analogWriteResolution(12);
   
  for(int i = 0; i<=255;i++){
    analogWrite(DAC1, sine[i]);
    delayMicroseconds(19);
  }

  digitalWrite(T1pin, LOW);   // PWM to T1 transistor
  digitalWrite(T2pin, LOW);   // PWM to T2 transistor

  digitalWrite(DAC0, LOW);   // PWM to T3 transistor
  digitalWrite(DAC1, LOW);   // PWM to T4 transistor

 delay(90); // specify time to delay until the next pulse based on frequency of biphasic pulses
}


