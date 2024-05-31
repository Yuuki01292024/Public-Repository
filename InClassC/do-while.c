#include <stdio.h>

int main(void)
{
  int i, sum;
  
  sum = 0;
  i = 1;
  do{
    sum += i;
    i++;
  }while( i <= 1000 );
  printf("sum = %d \n", sum);
  
  return 0;
}
