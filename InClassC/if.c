#include <stdio.h>

int main(void)
{
  double x;

  printf("enter a value: ");
  scanf("%lf", &x);
  
  if( x < 0.0 ){
    printf("%f < 0.0 \n", x);
  }
  else if( (x >= 0.0) && (x < 2.0) ){
    printf("0.0 <= %f < 2.0 \n", x);
  }
  else{
    printf("%f >= 2.0 \n", x);
  }
  
  return 0;
}
