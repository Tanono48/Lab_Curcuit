#include <Keypad.h>

const byte numRows = 4; // Number of rows on the keypad
const byte numCols = 4; // Number of columns on the keypad

const int LED_RED = 10;
const int LED_GREEN = 11;
const int LED_BLUE = 12;

bool is_red_on = false;
bool is_green_on = false;
bool is_blue_on = false;

// Keymap defines the key pressed according to the row and columns
char keymap[numRows][numCols] = 
{
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Keypad connections to the Arduino pins
byte rowPins[numRows] = {9, 8, 7, 6}; // Rows 0 to 3
byte colPins[numCols] = {5, 4, 3, 2}; // Columns 0 to 3

// Initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
    Serial.begin(9600);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
}

void loop()
{
    char keypressed = myKeypad.getKey();
    
    if (keypressed != NO_KEY)
    {
        Serial.println(keypressed);

        // Control LEDs based on key presses
        switch (keypressed) {
            case '1':
                is_red_on = !is_red_on;
                digitalWrite(LED_RED, is_red_on ? HIGH : LOW);
                break;
            case '2':
                is_green_on = !is_green_on;
                digitalWrite(LED_GREEN, is_green_on ? HIGH : LOW);
                break;
            case '3':
                is_blue_on = !is_blue_on;
                digitalWrite(LED_BLUE, is_blue_on ? HIGH : LOW);
                break;
            default:
                break;
        }
    }
}
