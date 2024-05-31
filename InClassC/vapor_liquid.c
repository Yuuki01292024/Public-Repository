#include <stdio.h>
#include <math.h>

int    k_max = 50;
double eps   = 1.0e-10;
double dx    = 1.0e-2;

double f(double, double);
double g(double, double);
double Delta_G_A(double);
double Delta_G_B(double);
double chi(double);
double bisect(double, double, double);

int main(void)
{
  double  xa, xb, fa, fb, x, y, T, dT,  T_min, T_max, i;

  T_min = 300.0;
  T_max = 400.0;
  dT = 0.01;
  T = T_min;
  
  do{
    xa = eps;
    xb = xa + dx;
    do{
      fa = f(T, xa);
      fb = f(T, xb);
      if( fa*fb < 0.0 ){
        x = bisect(T, xa, xb);
        y = g(T, x);
        printf("%f %f %f \n", T, x, y);
      }
      xa += dx;
      xb += dx;
    }while( xb < 1.0 );

    T = T + dT;
    
  }while(T <= T_max);
  
  return 0;
}

double f(double T, double x)
{
  return  1.0 - x*exp(-Delta_G_B(T) + chi(T)*(1.0 - x)*(1.0 - x)) - (1.0 - x)*exp(-Delta_G_A(T) + chi(T)*x*x);
}

double g(double T, double x)
{
  return  x*exp(-Delta_G_B(T) + chi(T)*(1.0 - x)*(1.0 - x));
}

double Delta_G_A(double T)
{
  return  (4890.0/T) - 13.11;
}

double Delta_G_B(double T)
{
  return  (4642.0/T) - 13.20;
}

double chi(double T)
{
  return  1.5;
}

double bisect(double T, double xa, double xb)
{
  int     k;
  double  xc, fb, fc;

  k = 0;
  do{
    xc = (xa + xb)/2.0;
    fc = f(T, xc);
    fb = f(T, xb);
    if( k >= k_max ){
      printf("PROGRAM ERROR\n");
      break;
    }
    if( fb*fc > 0 ){
      xb = xc;
    }
    else{
      xa = xc;
    }
    k++;
  }while( fabs(xb - xa) > eps );

  return  xc;
}
