int BUT1 = D0;

int LED1 = D2;

int knobButton = D3;
int knobA = D4;
int knobB = D5;

int lastStateCLK;
int encoderPos = 0;
long startTime = 0;

void setup() {
  pinMode(BUT1,INPUT_PULLUP);                                                                 // CLK and DT work together
  pinMode(LED1,OUTPUT);                                                                       // the encoder sends pulses on both pins as it turns
  pinMode(ENC_SW,INPUT_PULLUP);                  // Switch -                                      by comparing which one changes first
  pinMode(ENC_CLK,INPUT_PULLUP);                // Clock - one of the two rotation signal pins - the code can tell if you're turning
  pinMode(ENC_DATE,INPUT_PULLUP)                 // Date - the other  -                            clockwise or counter-clockwise.

  lastStateCLK = digitalRead(ENC_CLK);
  long startTime = millis();

}

void loop() {
  int currentCLK = digitalRead(ENC_CLK);

  if (currentCLK != lastStateCLK && currentCLK == HIGH) {
    if (digitalRead(ENC_DT) != currentCLK) {
      encoderPos++;
    } else {
      encoderPos--;
    }
  }

  lastStateCLK = currentCLK;

  if (digitalRead(BUT1) == LOW) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(ENC_SW) == LOW) {
    encoderPos = 0;
  }
}


