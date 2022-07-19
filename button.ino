
#include <ezButton.h>
const int BUTTON_PIN  = 2; // the number of the pushbutton pin
const int LED_PIN1    = 3;
const int LED_PIN2    = 4;// the number of the LED pin


ezButton button(BUTTON_PIN);  // create ezButton object that attach to pin 7;

// variables will change:
int ledState1 = HIGH; 
int ledState2 = LOW;   // the current state of LED
int i = 0;


void setup() {
  Serial.begin(9600);         // initialize serial
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);// set arduino pin to output mode
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if(button.isPressed()) {
    Serial.println("The button is pressed");

    // toggle state of LED
    ledState1 = !ledState1;
    ledState2 = !ledState2;

    i++;

    // control LED arccoding to the toggleed sate
    digitalWrite(LED_PIN1, ledState1);
    digitalWrite(LED_PIN2, ledState2); 
  }
  Serial.println(i);
  if( i - 3 == 0 ) {
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
  }else if ( i - 4 == 0){
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
  }
    
}
