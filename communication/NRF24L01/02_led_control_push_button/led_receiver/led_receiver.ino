#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

//Define CE(nrf module active) and CSN(SPI active)
RF24 radio(4,5);

//Address of transmitter
const byte address[]="00001";

//Data to be received
bool led_state = 1;

//LED Pin Define
#define led_pin 12


void setup(){
  Serial.begin(115200);

  //Define led as output mode
  pinMode(led_pin,OUTPUT);


  //Initialize communication
  if(!radio.begin()){
    Serial.print("Intializing the communication..");
    while(1);
  }

  Serial.println("Connected Succesfully..");

  //Power Amplifier
  radio.setPALevel(RF24_PA_LOW);

  //Set datarate
  radio.setDataRate(RF24_250KBPS);

  //Reading Pipe
  radio.openReadingPipe(0,address);

  //Receiver mode
  radio.startListening();

}

void loop(){

  if(radio.available()){
  
  //Receiving data from transmitter
  radio.read(&led_state,sizeof(led_state));
  Serial.println(led_state);

  //Toggle the led
  digitalWrite(led_pin,!led_state);

  }

}