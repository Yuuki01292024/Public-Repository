#include <stdio.h>

int Calc_summation(int, int);

int main(void)
{
  int answer;

  answer = Calc_summation(1, 1000);
  printf("answer = %d \n", answer);

  return 0;
}

int Calc_summation(int lower_limit, int upper_limit)
{
  int i, sum;

  sum = 0;
  for( i = lower_limit; i <= upper_limit; i++ ){
    sum += i;
  }
  
  return sum;
}
