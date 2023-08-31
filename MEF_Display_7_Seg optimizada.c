#define LED1 9
#define LED2 11
#define BUTTON 13
#define ANTI_REBOTE 40
#define TODOS_SALIDAS 0xff
#define VAL_MAX 15


uint8_t CONT = 0;
bool boton_presionado = false;

unsigned long int tiempo_a = 0;

void debounceFSM_init();
void debounceFSM_update();
void buttonPressed();
void buttonReleased();

typedef enum
{
  BUTTON_UP,
  BUTTON_FALLING,
  BUTTON_DOWN,
  BUTTON_RAISING,
}debounceState_t;

debounceState_t state;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT);
  tiempo_a = millis();
  debounceFSM_init();
  DDRD = TODOS_SALIDAS;
  PORTD = 0;
}

uint8_t display_cont[16]
{
  0b11000000, //0
  0b11111001, //1
  0b10100100, //2
  0b10110000, //3
  0b10011001, //4
  0b10010010, //5
  0b10000010, //6
  0b11111000, //7
  0b10000000, //8
  0b10010000, //9
  0b10001000, //A
  0b10000011, //B
  0b11000110, //C
  0b10100001, //D
  0b10000110, //E
  0b10001110  //F  
};
    
void loop()
{
  debounceFSM_update();
  if (boton_presionado)
  {
    CONT++;
    if (CONT>VAL_MAX)CONT = 0;
    boton_presionado = false;
  }
  PORTD=display_cont[CONT];
  //delay(500);
}

void debounceFSM_init(void)
{
  if (digitalRead(BUTTON)) state = BUTTON_UP;
  else  state = BUTTON_DOWN;
}

void debounceFSM_update()
{
  switch (state)
  {
    case BUTTON_UP:
    tiempo_a = millis();
    if (digitalRead(BUTTON) == LOW)
    {
      state = BUTTON_FALLING;
    }
    break;
    
    case BUTTON_FALLING:
    if (millis() - tiempo_a > ANTI_REBOTE)
    {
      tiempo_a = millis();
      if (digitalRead(BUTTON) == LOW)
      {
        state = BUTTON_DOWN;
        buttonPressed();
      }
      else
      {
        state = BUTTON_UP;
      }
    }
    break;
    
    case BUTTON_DOWN:
    tiempo_a = millis();
    if (digitalRead(BUTTON) == HIGH) 
    {
      state = BUTTON_RAISING;
    }
    break;
    
    case BUTTON_RAISING:
    if (millis() - tiempo_a > ANTI_REBOTE)
    {
      tiempo_a = millis();
      if (digitalRead(BUTTON) == HIGH)
      {
        state = BUTTON_UP;
        buttonReleased();
      }
      else
      {
        state = BUTTON_DOWN;
      }  
    }
    break;
  }
}

void buttonPressed()
{
  digitalWrite(LED1, !(digitalRead(LED1)));
  boton_presionado=true;
}

void buttonReleased()
{
  digitalWrite(LED2, !(digitalRead(LED2)));
}
