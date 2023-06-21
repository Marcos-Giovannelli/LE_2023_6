#include <stdio.h>
#define bits_m 23
#define bits_e 8
#define bits_s 1

void binario (void);

union pasaje
{
  struct 
  {
    unsigned int mantisa : bits_m;
    unsigned int exponente : bits_e;
    unsigned int signo : bits_s;
  };
  float val;
};

int main (void)
{
  binario();
  return(0);
}

void binario (void)
{
  union pasaje u;
  printf("Bienveido, ingrese un valor numérico con coma:");
  scanf("%f", &u.val);
  if (u.signo & 0x01) printf("1");
  else printf("0");
  for (int n=(bits_e-1); n>=0; n--)
  {
    if ((u.exponente>>n & 0x01)==1)
    {
     printf("1"); 
    }
    else printf("0");
  }
  for (int n=(bits_m-1); n>=0; n--)
  {
    if ((u.mantisa>>n & 0x01)==1)
    {
      printf("1");
    }
    else printf("0");
  }
}
