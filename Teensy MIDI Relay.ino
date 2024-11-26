//variables setup

  byte incomingByte;
  byte note;
  byte velocity;
  int noteDown = LOW;
  int state=0;  // state machine variable 0 = command waiting : 1 = note waitin : 2 = velocity waiting
  int baseNote = 60;  // lowest note
  // use different values of baseNote to select the MIDI octiave
  // 24 for octiave 1 -- 36 for octiave 2 -- 48 for octiave 3 -- 60 for octiave 4 -- 72 for octiave 5
  // 84 for octiave 6 -- 96 for octiave 7
 
// play only notes in the key of C (that is no sharps or flats) define pin numbers:-
  byte playArray[] =    { 9,  8,  7,  6,  5 };
// corrisponding to note 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48 - for base note = 36 or C2
int strobe = 13;   // select the pin for the monostable
int channel = 1; // MIDI channel to respond to (in this case channel 2) chnage this to change the channel number
                 // MIDI channel = the value in 'channel' + 1

//setup: declaring iputs and outputs and begin serial
void setup() {
  digitalWrite(9, HIGH);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
digitalWrite(6, HIGH);
digitalWrite(5, HIGH);

  pinMode(strobe,OUTPUT);   // declare the strobe pin as output
  pinMode(9,OUTPUT);        // declare the solenoid's pins as outputs
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
 
  state = 0;  // initilise state machine variable
  //start serial with MIDI baudrate 31250 or 38400 for debugging
  Serial.begin(115200);        
  digitalWrite(strobe,LOW);  
}

//loop: wait for serial data, and interpret the message
void loop () {


  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
     digitalWrite(strobe,LOW);    // clear any previous strobe
   switch (state){
      case 0:
    // look for as status-byte, our channel, note on
    if (incomingByte== (144 | channel)){
         noteDown = LOW;
         state=1;
        }
    // look for as status-byte, our channel, note off
    if (incomingByte== (128 | channel)){
         noteDown = HIGH;
         state=1;
        }
       
       case 1:
       // get the note to play or stop
       if(incomingByte < 128) {
          note=incomingByte;
          state=2;
       }
       else{
       state = 0;  // reset state machine as this should be a note number
       }
       break;
       
       case 2:
       // get the velocity
       if(incomingByte < 128) {
         playNote(note, incomingByte, noteDown); // fire off the solenoid
       }
         state = 0;  // reset state machine to start            
     }
  }
}

void playNote(byte note, byte velocity, int down){
  // if velocity = 0 on a 'Note ON' command, treat it as a note off
  if ((down == LOW) && (velocity == 0)){
      down = HIGH;
  }
 //since we can't play all notes we only action notes between 36 & 49
 if(note>=baseNote && note<(baseNote + 20)){
   byte myPin=playArray[note-baseNote]; // to get a pin number between 2 and 9
   if(myPin != 0) {
     digitalWrite(myPin, down); // play it if it is one of our notes
     if(down == HIGH) digitalWrite(strobe, HIGH); // strobe high to monostable for note on
   }
 }

}
