#include <stdio.h>

double x[10];
double Calc_average(void);

int main(void)
{
  int    i;
  double average;

  for( i = 0; i < 10; i++ ){
    x[i] = 2.0 * i;
    printf("i = %d, x[%d] = %f \n", i, i, x[i]);
  }

  average = Calc_average();
  printf("average = %f \n", average);

  return 0;
}

double Calc_average(void)
{
  int    i, sum;
  double ave;

  sum = 0;
  ave = 0.0;
  for( i = 0; i < 10; i++ ){
    ave += x[i];
    sum++;
  }
  
  return ave/sum;
}
