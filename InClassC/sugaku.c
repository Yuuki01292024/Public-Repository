#include <stdio.h>
#include <math.h>

int main(void)
{
  int    i;
  double x[10], y[10];
  for( i = 0; i < 10; i++ ){
    x[i] = 0.1 * i;
    y[i] = tanh(x[i]);
    printf("x[%d] = %f, y[%d] = %f \n", i, x[i], i, y[i]);
  }

  return 0;
}
