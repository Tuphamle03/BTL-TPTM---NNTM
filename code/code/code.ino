// Chân kết nối HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Chân LED
const int ledPin = 13;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // (Tùy chọn) để theo dõi khoảng cách
}

void loop() {
  // Phát xung siêu âm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Đo độ rộng xung hồi lại
  long duration = pulseIn(echoPin, HIGH);
  
  // Tính khoảng cách (cm)
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Nếu tay gần hơn 20 cm thì sáng đèn
  if (distance > 0 && distance <= 20) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}