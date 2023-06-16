int PIN_R = D5;
int PIN_G = D8;
int PIN_B = D6;

int r = 0;
int g = 0;
int b = 0;


struct rgb {
  byte r, g, b;  
};

const rgb RED = {255, 0, 0};
const rgb GREEN = {0, 255, 0};
const rgb BLUE = {0, 0, 255};
const rgb ORANGE = { 255, 165, 0 }; 
const rgb YELLOW = { 255, 255, 0 };
const rgb PURPLE = { 148, 0, 211 };
const rgb INDIGO = { 75, 0, 130 };
//const rgb VIOLET = { 238, 130, 238 };
//const rgb CHOCOLATE = {210, 105, 30 };

const rgb WHITE = { 255, 255, 255 };
const rgb AQUA = { 0, 180, 180 };
const rgb OFF = { 0, 0, 0 };


void setup() {
  //Serial.begin(9600);
  //pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output

  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);

  analogWrite(PIN_R, 0);
  analogWrite(PIN_G, 0);
  analogWrite(PIN_B, 0);
}

// the loop function runs over and over again forever
void loop() {
  //Serial.println("RED");
  //smooth(RED);
  
  //Serial.println("ORANGE");
  //smooth(ORANGE);
  
  //Serial.println("YELLOW");
  //smooth(YELLOW);
  
  Serial.println("GREEN");
  smooth(GREEN);

  Serial.println("AQUA");
  smooth(AQUA);

  Serial.println("BLUE");
  smooth(BLUE);

  Serial.println("INDIGO");
  smooth(INDIGO);

  Serial.println("PURPLE");
  smooth(PURPLE);

}

void setrgb(int _r, int _g, int _b, int tempo){
  analogWrite(PIN_R, _r);
  analogWrite(PIN_G, _g);
  analogWrite(PIN_B, _b);
  delay(tempo);
}

void smooth(rgb cor){
  while (r != cor.r || g != cor.g || b != cor.b) {
    if (r < cor.r) r += 1;
    if (r > cor.r) r -= 1;

    if (g < cor.g) g += 1;
    if (g > cor.g) g -= 1;

    if (b < cor.b) b += 1;
    if (b > cor.b) b -= 1;
    
    setColor();
    delay(20);
  } 
  delay(2000);
}

void setColor(){
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B, b);
}
