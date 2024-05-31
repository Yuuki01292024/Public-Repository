#include <stdio.h>
#include <math.h>

#define eps 1.0e-6

double f(double);

int main(void)
{
  int     i;
  double  a, b, c, fb, fc;

  i  = 0;
  a  = 0.0;
  b  = 1.0;
  c  = (a + b)/2.0;
  fb = f(b);
  fc = f(c);

  do{
    printf("%d %e %e\n", i, c, fabs(c - 1.0/sqrt(2.0)));
    if( fb*fc > 0 ){
      b = c;
    }
    else{
      a = c; 
    }
    c  = (a + b)/2.0;
    fc = f(c);
    i++;
  }while( fabs(b - a) > eps );
  printf("%d %e\n", i, c);

  return 0;
}

double f(double x)
{
  return x*x - 0.5;
}
