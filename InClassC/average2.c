#include <stdio.h>

int main(void)
{
  int    i, sum;
  double j, x[10], ave, var, a, b;

  printf("enter a value: ");
  scanf("%lf", &j);

  for( i = 0; i < 10; i++ ){
    x[i] = j  * i;
    
    printf("i = %d, x[%d] = %f \n", i, i, x[i]);
  }
  sum = 0;
  ave = 0.0;
  var = 0.0;
  for( i = 0; i < 10; i++ ){
    ave += x[i];
    sum++;
  }
  ave /= sum;

  printf("average = %f \n", ave);

  for( i = 0; i < 10; i++ ){
    var += ( x[i] - ave ) * ( x[i] - ave );
  }
  var /= sum;
  
  printf("variance = %f \n", var);

  a = 1;
  while(1){
    a = a - (a * a - var) / (2 * a);
    b = a * a - var;
    if((b <= 0.00000001) && (b >= -0.00000001)){
      break;
    }	
  }

  printf("standard diviation = %f \n", a);
  
  return 0;
}
