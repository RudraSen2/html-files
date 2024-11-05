#include <SoftwareSerial.h>

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define EN1 2
// #define EN2 10

SoftwareSerial btSerial(0, 1);  // RX, TX

String data;
int btVal;

int leftValue = 0;
int rightValue = 0;

void setup() {
  // Serial.begin(115200);
  // Right
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Left
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(EN1, HIGH);
  // digitalWrite(EN2, HIGH);

  digitalWrite(IR1, HIGH);
  digitalWrite(IR2, HIGH);

  btSerial.begin(9600);
}

void loop() {
  while (btSerial.available()) {
    {
      data = btSerial.readStringUntil('\n');
      Serial.print(data);
    }

    btVal = (data.toInt());
    Serial.print("Bluetooth Value ");
    Serial.println(btVal);

    left = digitalRead(IR1);
    right = digitalRead(IR2);

    switch (btVal) {
      case 1:
        Serial.println("Forward");
        forward();
        break;

      case 2:
        Serial.println("Reverse");
        reverse();
        break;

        case 3:
          Serial.println("Left");
          left();
          break;

        case 4:
          Serial.println("Right");
          right();
          break;

      case 3:
        Serial.println("Stop");
        stoprobot();
        break;
    }
  }


  if (btSerial.available() < 0) {
    // Serial.println("No Bluetooth Data ");
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stoprobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
