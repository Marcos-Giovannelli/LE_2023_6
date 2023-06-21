#include <stdio.h>

void conversion (void);

union convertir 
{
  float fl;
  unsigned char hex[4];
}hexa;


int main(void) 
{
  printf("Bienvenido al conversor de numeros con coma a hexadecimales\n");
  conversion();
  return 0;
}

void conversion (void)
{
  printf("Ingrese un numero con coma:");
  scanf("%f", &hexa.fl);
  printf("Equivalente en IEEE 754: 0x");
  printf("%.2X", hexa.hex[3]);
  printf("%.2X", hexa.hex[2]);
  printf("%.2X", hexa.hex[1]);
  printf("%.2X", hexa.hex[0]);
  
}
