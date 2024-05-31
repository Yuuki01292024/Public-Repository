#include <stdio.h>

int main(void)
{
  int    i, j;
  double d1, d2, x, y, z;
  
  x = 2.2;
  y = 5.6;
  printf("x = %f, y = %f \n", x, y);

  i = x;
  printf("i = %d \n", i);
  i = y;
  printf("i = %d \n", i);

  i = x * y;
  printf("i = %d \n", i);

  i = 20;
  j = x / i;
  z = x / i;
  printf("j = %d, z = %f \n", j, z);

  j = 30;
  d1 = i;
  d2 = j;
  z = d1 / d2;
  printf("z = %f \n",z);

  y = x + y;
  x = y - x;
  y = y - x;
  
  printf("x = %f, y = %f \n", x, y);

  return 0;
}
