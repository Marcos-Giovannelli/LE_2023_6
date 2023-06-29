#include <stdio.h>

float hexa;

void conversion_hexa(float numero) {
    unsigned char *puntero = (unsigned char *)&numero;
    
    printf("Valor flotante: %f\n", numero);
    
    printf("Representación hexadecimal: 0x");
    for (int i = sizeof(float) - 1; i >= 0; i--) {
        printf("%02X", puntero[i]);
    }
    printf("\n");
}

int main() {
  printf("Ingrese un valor decimal:");
  scanf("%f", &hexa);
    float valor = hexa;
    conversion_hexa(valor);
    return 0;
}
