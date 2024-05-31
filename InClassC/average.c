#include <stdio.h>

int main(void)
{
  int    i, sum;
  double x[10], average;

  for( i = 0; i < 10; i++ ){
    x[i] = 2.0 * i;
    printf("i = %d, x[%d] = %f \n", i, i, x[i]);
  }
  sum = 0;
  average = 0.0;
  for( i = 0; i < 10; i++ ){
    average += x[i];
    sum++;
  }
  average /= sum;
  printf("average = %f \n", average);

  return 0;
}
