#include <stdio.h>
#include <math.h>

#define eps 1.0e-6

double f(double);
double g(double);

int main(void)
{
  int     i;
  double  x0, x1, f0, g0;

  i  = 0;  
  x0 = 0.5;
  do{
    printf("%d %e %e\n", i, x0, fabs(x0 - 1.0/sqrt(2.0)));
    f0 = f(x0);
    g0 = g(x0);
    x1 = x0 - f0/g0;
    x0 = x1;
    i++;
  }while( fabs(f0/g0) > eps );
  printf("%d %e\n", i, x0);

  return 0;
}

double f(double x)
{
  return x*x - 0.5;
}

double g(double x)
{
  return 2.0*x;
}
