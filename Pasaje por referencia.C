include <stdio.h>

void cambiarValor(int *val) {
    *val = 20;
}

int main() {
    int num = 10;
    printf("Valor antes de llamar a la función: %d\n", num);
    cambiarValor(&num);
    printf("Valor después de llamar a la función: %d\n", num);
    return 0;
}
