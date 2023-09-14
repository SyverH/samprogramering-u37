const int LED_PIN = 13;
const int BUTTON_PIN = 2;

bool buttonState = false;

void updateButton() {
    buttonState = digitalRead(BUTTON_PIN);
}

void blinkLed()
{
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
}

void setup()
{
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
    updateButton();
    blinkLed();
    Serial.println(buttonState);
}