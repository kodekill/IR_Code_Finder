#include <IRremote.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
int count = 0;

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println("results: ");
    Serial.print("hex ");
    Serial.println(results.value, HEX);
    Serial.print("dec ");
    Serial.println(results.value, DEC); 
    
    irrecv.resume(); // Receive the next value
    delay(200);
   // count = 0;
  }
  
  else {
  //  count ++;
   // Serial.print("count = ");
   // Serial.println(count);
  }
}
