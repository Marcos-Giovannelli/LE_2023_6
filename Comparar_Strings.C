//Consigan 1: Realizar una función que compare dos strings (pasados como parámetros) y devuelva 0 si son iguales o 1 si son distintos

#include <stdio.h>

int compareStrings(char *string1, char *string2) {
    while (*string1 == *string2) {
        if (*string1 == '\0' || *string2 == '\0')
            break;
        string1++;
        string2++;
    }
  
    if (*string1 == '\0' && *string2 == '\0')
        return 0; // son iguales
    else
        return 1; // son diferentes
}

int main() {
  char string1[20];
  char string2[20];
  printf("Ingrese la primer palabra maximo 4 caracteres: ");
  scanf("%s", string1);
  printf("\nIngrese la segunda palabra maximo 4 caracteres: ");
  scanf("%s", string2);
  int result;

  result = compareStrings(string1, string2);
  
  if (result == 0) {
        printf("Las palabras son iguales\n");
    } else {
        printf("Las palabras son diferentes\n");
    }
    return 0;
}
