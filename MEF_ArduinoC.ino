#define LED1 9
#define LED2 8
#define BUTTON 7
#define ANTI_REBOTE 40

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
}

void loop()
{
  debounceFSM_update();
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
}

void buttonReleased()
{
  digitalWrite(LED2, !(digitalRead(LED2)));
}
