#include <stdio.h>

int main(void)
{
  int i, sum;
  
  sum = 0;
  printf("sum = %d", sum);
  
  for( i = 1; i <= 100; i++ ){
    
    if( i%2 == 1 ){
      sum += i;
      printf("+ %d", i);
    }
    
    else{}
  }
  
  printf("\n sum = %d \n", sum);
  
  return 0;
}
