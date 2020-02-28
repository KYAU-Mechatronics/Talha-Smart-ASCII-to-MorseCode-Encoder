#include <Wire.h>
#include <BluetoothSerial.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

unsigned char BT_Icon[] =
{
  0b00000000, 0b00000000,
  0b00000001, 0b10000000,
  0b00000001, 0b11000000,
  0b00000001, 0b01100000,
  0b00001001, 0b00110000,
  0b00001101, 0b00110000,
  0b00000111, 0b01100000,
  0b00000011, 0b11000000,
  0b00000001, 0b10000000,
  0b00000011, 0b11000000,
  0b00000111, 0b01100000,
  0b00001101, 0b00110000,
  0b00001001, 0b00110000,
  0b00000001, 0b01100000,
  0b00000001, 0b11000000,
  0b00000001, 0b10000000,
};

unsigned char BT_NC[] =
{
  0b00000000, 0b00000000,
  0b00000011, 0b11100000,
  0b00001111, 0b11111000,
  0b00011111, 0b11111100,
  0b00111110, 0b00111110,
  0b00111000, 0b01111110,
  0b01110000, 0b11111111,
  0b01110001, 0b11110111,
  0b01110011, 0b11000111,
  0b01110111, 0b10000111,
  0b00111111, 0b00001110,
  0b00111110, 0b00011110,
  0b00011111, 0b11111100,
  0b00001111, 0b11111000,
  0b00000011, 0b11100000,
  0b00000000, 0b00000000,
};

unsigned char bulb_off[] =
{
  0b00000000, 0b00000000,
  0b00000011, 0b11100000,
  0b00000100, 0b00010000,
  0b00001000, 0b00001000,
  0b00010000, 0b00000100,
  0b00010000, 0b00000100,
  0b00010000, 0b00000100,
  0b00010000, 0b00000100,
  0b00010000, 0b00000100,
  0b00001000, 0b00001000,
  0b00000100, 0b00010000,
  0b00000011, 0b11100000,
  0b00000010, 0b00100000,
  0b00000011, 0b11100000,
  0b00000010, 0b00100000,
  0b00000011, 0b11100000,
};


unsigned char bulb_on[] =
{
  0b00000000, 0b00000000,
  0b00000011, 0b11100000,
  0b00000111, 0b11110000,
  0b00001111, 0b11111000,
  0b00011111, 0b11111100,
  0b00011111, 0b11111100,
  0b00011111, 0b11111100,
  0b00011111, 0b11111100,
  0b00011111, 0b11111100,
  0b00001111, 0b11111000,
  0b00000100, 0b00010000,
  0b00000011, 0b11100000,
  0b00000010, 0b00100000,
  0b00000011, 0b11100000,
  0b00000010, 0b00100000,
  0b00000011, 0b11100000,
};


#define OLED_RESET 4
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
BluetoothSerial SerialBT;

const int led = 2;
const int BT_indic_led = 27;

String code = "";
int len = 0;
char ch;
char new_char;
int i, pos, DelayUnit = 250; //Per unit time = 250ms
byte BT_Status;


void dot()
{
  Serial.print(".");
  display.fillRect(110, 0, 20, 20, BLACK);
  display.drawBitmap(112, 0, bulb_on, 16, 16, 1);
  display.display();
  digitalWrite(led, HIGH);
  delay(DelayUnit);
  display.fillRect(110, 0, 20, 20, BLACK);
  display.drawBitmap(112, 0, bulb_off, 16, 16, 1);
  display.display();
  digitalWrite(led, LOW);
  Serial.print("<D>");
  delay(DelayUnit);
}

void dash()
{
  Serial.print("-");
  display.fillRect(110, 0, 20, 20, BLACK);
  display.drawBitmap(112, 0, bulb_on, 16, 16, 1);
  display.display();
  digitalWrite(led, HIGH);
  delay(DelayUnit * 3);
  display.fillRect(110, 0, 20, 20, BLACK);
  display.drawBitmap(112, 0, bulb_off, 16, 16, 1);
  display.display();
  digitalWrite(led, LOW);
  Serial.print("<D>");
  delay(DelayUnit);
}

void A()
{
  dot();
  dash();
}
void B()
{
  dash();
  dot();
  dot();
  dot();
}
void C()
{
  dash();
  dot();
  dash();
  dot();
}
void D()
{
  dash();
  dot();
  dot();
}
void E()
{
  dot();
}
void f()
{
  dot();
  dot();
  dash();
  dot();
}
void G()
{
  dash();
  dash();
  dot();
}
void H()
{
  dot();
  dot();
  dot();
  dot();
}
void I()
{
  dot();
  dot();
}
void J()
{
  dot();
  dash();
  dash();
  dash();
}
void K()
{
  dash();
  dot();
  dash();
}
void L()
{
  dot();
  dash();
  dot();
  dot();
}
void M()
{
  dash();
  dash();
}
void N()
{
  dash();
  dot();
}
void O()
{
  dash();
  dash();
  dash();
}
void P()
{
  dot();
  dash();
  dash();
  dot();
}
void Q()
{
  dash();
  dash();
  dot();
  dash();
}
void R()
{
  dot();
  dash();
  dot();
}
void S()
{
  dot();
  dot();
  dot();
}
void T()
{
  dash();
}
void U()
{
  dot();
  dot();
  dash();
  
}
void V()
{
  dot();
  dot();
  dot();
  dash();
}
void W()
{
  dot();
  dash();
  dash();
}
void X()
{
  dash();
  dot();
  dot();
  dash();
  
}
void Y()
{
  dash();
  dot();
  dash();
  dash();
}
void Z()
{
  dash();
  dash();
  dot();
  dot();
}
void one()
{
  dot();
  dash();
  dash();
  dash();
  dash();
}
void two()
{
  dot();
  dot();
  dash();
  dash();
  dash();
}
void three()
{
  dot();
  dot();
  dot();
  dash();
  dash();
}
void four()
{
  dot();
  dot();
  dot();
  dot();
  dash();
}
void five()
{
  dot();
  dot();
  dot();
  dot();
  dot();
}
void six()
{
  dash();
  dot();
  dot();
  dot();
  dot();
}
void seven()
{
  dash();
  dash();
  dot();
  dot();
  dot();
}
void eight()
{
  dash();
  dash();
  dash();
  dot();
  dot();
}
void nine()
{
  dash();
  dash();
  dash();
  dash();
  dot();
}
void zero()
{
  dash();
  dash();
  dash();
  dash();
  dash();
}
void morse()
{
  if (ch == 'A' || ch == 'a')
  {
    A();
  }
  else if (ch == 'B' || ch == 'b')
  {
    B();
  }
  else if (ch == 'C' || ch == 'c')
  {
    C();
  }
  else if (ch == 'D' || ch == 'd')
  {
    D();
  }
  else if (ch == 'E' || ch == 'e')
  {
    E();
  }
  else if (ch == 'f' || ch == 'f')
  {
    f();
  }
  else if (ch == 'G' || ch == 'g')
  {
    G();
  }
  else if (ch == 'H' || ch == 'h')
  {
    H();
  }
  else if (ch == 'I' || ch == 'i')
  {
    I();
  }
  else if (ch == 'J' || ch == 'j')
  {
    J();
  }
  else if (ch == 'K' || ch == 'k')
  {
    K();
  }
  else if (ch == 'L' || ch == 'l')
  {
    L();
  }
  else if (ch == 'M' || ch == 'm')
  {
    M();
  }
  else if (ch == 'N' || ch == 'n')
  {
    N();
  }
  else if (ch == 'O' || ch == 'o')
  {
    O();
  }
  else if (ch == 'P' || ch == 'p')
  {
    P();
  }
  else if (ch == 'Q' || ch == 'q')
  {
    Q();
  }
  else if (ch == 'R' || ch == 'r')
  {
    R();
  }
  else if (ch == 'S' || ch == 's')
  {
    S();
  }
  else if (ch == 'T' || ch == 't')
  {
    T();
  }
  else if (ch == 'U' || ch == 'u')
  {
    U();
  }
  else if (ch == 'V' || ch == 'v')
  {
    V();
  }
  else if (ch == 'W' || ch == 'w')
  {
    W();
  }
  else if (ch == 'X' || ch == 'x')
  {
    X();
  }
  else if (ch == 'Y' || ch == 'y')
  {
    Y();
  }
  else if (ch == 'Z' || ch == 'z')
  {
    Z();
  }
  else if (ch == '0')
  {
    zero();
  }
  else if (ch == '1')
  {
    one();
  }
  else if (ch == '2')
  {
    two();
  }
  else if (ch == '3')
  {
    three();
  }
  else if (ch == '4')
  {
    four();
  }
  else if (ch == '5')
  {
    five();
  }
  else if (ch == '6')
  {
    six();
  }
  else if (ch == '7')
  {
    seven();
  }
  else if (ch == '8')
  {
    eight();
  }
  else if (ch == '9')
  {
    nine();
  }
  else if (ch == ' ')
  {
    /*delay(DelayUnit * 7);
    //Serial.print("/ ");
    Serial.print("<w*7>");*/
  }
  else
    Serial.print("");
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_SRV_OPEN_EVT) {
    BT_Status = 1;
    Serial.println("Client Connected");
  }

  if (event == ESP_SPP_CLOSE_EVT ) {
    Serial.println("Client disconnected");
    BT_Status = 0;
  }
}

void String2Morse()
{
  len = code.length();

  SerialBT.print("Text to Encode: ");
  SerialBT.print(code);
  SerialBT.print("Encoding progress: ");
  for (i = 0, pos = 0; i < len; i++, pos += 6)
  {
    ch = code.charAt(i);
    display.setTextSize(1);
    display.setCursor(pos, 23);
    display.print(code.charAt(i));
    display.display();
    SerialBT.print(code.charAt(i));
    if (ch == ' ') {
      delay(DelayUnit * 7);
      //Serial.print("/ ");
      Serial.print("<W7>");
    } else {
      morse();
      if (code.charAt(i + 1) != ' ')
      {
        delay(DelayUnit * 3);
        Serial.print("<L3>");
      }
    }
  }

  display.clearDisplay();
  SerialBT.print("Yeah, Encoding Finished!");
  SerialBT.println(" ");
  SerialBT.println();
}

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(INVERSE);
  SerialBT.begin("ASCII to Morse Encoder");
  pinMode(led, OUTPUT);
  pinMode(BT_indic_led, OUTPUT);
  display.setTextSize(1);
  display.setCursor(3, 20);
  display.fillRect(0, 18, 88, 10, WHITE);
  display.print("ASCII to Morse");
  display.setTextSize(2);
  display.setCursor(0, 30);
  display.print("ENCODER");
  display.display();
  delay(2500);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.print("SYSTEM Ready!");
  display.setCursor(0, 30);
  display.print("Connect ESP32 to yourphone using BT & sendASCII data to encode.");
  display.display();
  Serial.println("SYSTEM Ready!");
}

void loop() {
  while (Serial.available() > 0 || SerialBT.available() > 0)
  {
    display.clearDisplay();
    display.setTextSize(1);
    Serial.print("Encoding the text: ");
    display.setCursor(0, 14);
    display.print("Encoding the text: ");
    if (Serial.available() > 0)
    {
      code = Serial.readString();
    }
    else if (SerialBT.available() > 0)
    {
      code = SerialBT.readString();
    }

    Serial.print(code);
    //display.setCursor(2, 23);
    //display.print(code);
    display.setCursor(0, 36);
    display.print("Please wait until it is finished...");
    display.display();
    Serial.print("Generated Morse Code: ");
    String2Morse();
    Serial.println("");
    Serial.println("Encoding FINISHED!");
    display.clearDisplay();
    display.setCursor(0, 28);
    display.print("Encoding DONE...!");
    display.setCursor(0, 38);
    display.print("Ready to ENCODE next.");
    display.display();
    delay(3000);
    Serial.println("Ready to ENCODE next...");
    Serial.println("");
  }

  display.setTextSize(1);
  display.setCursor(0, 0);
  if (BT_Status == 1)
  {
    digitalWrite(BT_indic_led, HIGH);
    display.clearDisplay();
    display.drawBitmap(112, 0, BT_Icon, 16, 16, 1);
    display.setCursor(0, 0);
    display.print("BT: Connected");
    display.setCursor(0, 16);
    display.print("SYSTEM Standby!");
    display.setCursor(0, 30);
    display.print("Now send ASCII data  from your Smartphone or PC to encode.");
    display.display();
  }
  else if (BT_Status == 0)
  {
    digitalWrite(BT_indic_led, LOW);
    display.fillRect(0, 0, 128, 15, BLACK);
    display.drawBitmap(112, 0, BT_NC, 16, 16, WHITE);
    //display.display();
    display.print("BT: Disconnected");
    display.fillRect(0, 28, 128, 25, BLACK);
    display.setCursor(0, 30);
    display.print("Connect ESP32 to yourphone using BT & sendASCII data to encode.");
    display.display();
  }
  delay(200);
  SerialBT.register_callback(callback);
}
