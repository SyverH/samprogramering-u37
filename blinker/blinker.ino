/////////////////////////
///////// Button ////////
/////////////////////////

const int BUTTON_PIN = 2;

bool buttonState = false;

void updateButton()
{
    buttonState = digitalRead(BUTTON_PIN);
}

/////////////////////////
///////// Led ///////////
/////////////////////////

const int LED_PIN = 13;

bool ledState = false;

void updateLed()
{
    digitalWrite(LED_PIN, ledState);
}

/////////////////////////
///////// Led Timer /////
/////////////////////////

unsigned long timer = 0;

void updateLedTimer()
{
    if ((millis() - timer) >= 200)
    {
        timer = millis();

        ledState = !ledState;
    }
}

/////////////////////////
///////// Main Code /////
/////////////////////////

void setup()
{
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
    updateButton();

    if (buttonState)
    {
        updateLedTimer();
    }
    else
    {
        ledState = false;
    }

    updateLed();
}