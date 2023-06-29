#include <stdio.h>

float num;

void floatAbinario(float numero) {
    unsigned char *puntero = (unsigned char *)&numero;
    
    printf("Valor flotante: %f\n", numero);
    
    printf("Representación binaria: ");
    for (int a = sizeof(float) - 1; a >= 0; a--) {
        for (int b = 7; b >= 0; b--) {
            unsigned char bit = (puntero[a] >> b) & 1;
            printf("%u", bit);
        }
    }
    printf("\n");
}

int main() {
  printf("Ingresar un valor decimal:");
  scanf("%f", &num);
    float valor = num;
    floatAbinario(valor);
    
    return 0;
}
