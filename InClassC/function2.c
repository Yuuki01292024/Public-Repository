#include <stdio.h>

int Calc_summation(int, int);

int main(void)
{
  int answer;
  int x, y;

  printf("enter lower_limit: ");
  scanf("%d", &x);

  printf("enter upper_limit: ");
  scanf("%d", &y);
  

  answer = Calc_summation(x, y);
  printf("answer = %d \n", answer);

  return 0;
}

int Calc_summation(int lower_limit, int upper_limit)
{
  int i, sum_even;

  sum_even = 0;
  for( i = lower_limit; i <= upper_limit; i++ ){
     if( i%2 == 0 ){
      sum_even += i;
      }
   
  }
  
  return sum_even;
}
