const int pingPin = 7;
const int echoPin = 6;
const int ledPin = 13;

void setup() {
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
}

void loop() {
	pinMode(pingPin, OUTPUT);
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pingPin, LOW);
	pinMode(echoPin, INPUT);
	long duration = pulseIn(echoPin, HIGH);
	long inches = microsecondsToInches(duration);
	Serial.print(inches);
	Serial.println("in");
	if (inches < 100) {
		digitalWrite(ledPin, HIGH);
		delay(inches * 10);
	}
	digitalWrite(ledPin, LOW);
	delay(100);
}

long microsecondsToInches(long mcs) {
	return mcs / 74 / 2;
}
