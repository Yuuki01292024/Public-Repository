#include <stdio.h>

int main(void)
{
  int i, sum1, sum2;
  
  sum1 = 0;
  i = 1;
  do{
    if( i%2 == 1 ){
      sum1 += i;
    }
    
    i++;
    
  }while( i <= 100 );
  printf("sum1 = %d \n", sum1);
  
  sum2 = 0;
  i = 1;
 do{
    if( i%2 != 1 ){
      sum2 += i;
    }
    
    i++;
    
  }while( i <= 100 );
  printf("sum2 = %d \n", sum2);
  
  
  return 0;
}
