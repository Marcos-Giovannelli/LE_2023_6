#include <stdio.h>
#include <string.h>

#define NOMBRE 80
#define DNI 10
#define APELLIDO 50
#define CURSO 2
#define LIM_ALUMNOS 30


typedef struct alumnos { //estructura de datos de alumno
    int edad;
    char nombre[NOMBRE];
    char dni[DNI];
    char apellido[APELLIDO];
    char curso[CURSO];
} alumno;

int main() { //ingresar datos del alumno
  alumno alumnos[1];
  int eleccion=1;
  int buscar=1;
  int i=0;
  for(i=0;i<LIM_ALUMNOS;i++){ //ingreso y escaneo de datos
    printf("Ingrese los datos del alumno:\n");
    printf("  Nombre: ");
    scanf("\n %s", alumnos[i].nombre);
    printf("  Apellido: ");
    scanf(" %s", alumnos[i].apellido);
    printf("  Edad: ");
    scanf("%d", &alumnos[i].edad);
    printf("  DNI: ");
    scanf(" %s", alumnos[i].dni);
    printf("  Curso: ");
    scanf(" %s", alumnos[i].curso);
    printf ("Colocar 1 si desea ingresar otro alumno, si no coloque 0 \n");
    scanf(" %d", &eleccion);
    if(eleccion!=1)break;
  }
  
  printf("Gracias por utilizar nuetra plataforma");//fin del programa
  return 0;
}
