#include <stdio.h>

int main(void)
{
  int    i;
  double a, x[10];

  for( i = 0; i < 10; i++ ){
    x[i] = 2.0 * i;
    printf("i = %d, x[%d] = %f \n", i, i, x[i]);
  }

  a = x[1] + x[5];
  printf("a = %f \n", a);

  return 0;
}
