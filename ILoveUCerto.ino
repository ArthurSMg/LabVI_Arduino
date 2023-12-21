const int buttoPin = 4;  
int buttoState = 0;




int trigPin=12;
int echoPin=11;
int pingTravelTime;



// Botao =================================================
const int buttonPin = 7;
int buttonState = 0;
// =======================================================

int n = 1;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);

// initialize the pushbutton pin as an input:
pinMode(buttoPin, INPUT);
}

void loop() {

  if (buttoState == LOW) {
  buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      float time = 0;
      for (int counter = 1; counter <= 1000; counter = counter + 1)
      {
        digitalWrite(trigPin,LOW);
        delayMicroseconds(10);
        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
        pingTravelTime=pulseIn(echoPin,HIGH);
        time = time + pingTravelTime;
      }
    
      time = time/1000;
      float vel = (n*60000)/time;
      
      delay(100);
      Serial.println("\t");
      Serial.println(n);
      Serial.print("Distancia: ");
      Serial.print(3*n);
      Serial.print("cm \t");
      Serial.print("tempo: ");
      Serial.print(time);
      Serial.println("mum \t");
      Serial.println("Velocidade: ");
      Serial.print(vel);

      vel = 0.0;
      n = n + 1;
      }
  }
      if (buttonState == LOW) {
        // read the state of the pushbutton value:
      buttoState = digitalRead(buttoPin);
      // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
      if (buttoState == HIGH) {
        n = n - 1;
        Serial.println(n);
        delay(1000);
      } 
      }
  }