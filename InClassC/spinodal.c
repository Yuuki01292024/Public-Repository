#include <stdio.h>
#include <math.h>

int    k_max = 50;
double eps   = 1.0e-10;
double dx    = 1.0e-2;

double f(double, double, double);
double bisect(double, double, double, double);

int main(void)
{
  double  n, chi, dchi,  phi, xa, xb, fa, fb;

  n  = 3.0;
  chi = 0.0;
  dchi = 0.01;

  do{
  xa  = eps;
  xb  = xa + dx;
  chi = chi + dchi;
    do{
    fa = f(n, chi, xa);
    fb = f(n, chi, xb);
    if( fa*fb < 0.0 ){
      phi = bisect(n, chi, xa, xb);
      printf("%f %f \n", chi, phi);
    }
    xa += dx;
    xb += dx;
    }while( xb < 1.0 );

  }while(chi < 2.0);
  return 0;
}

double f(double n, double chi, double phi)
{
  return  1.0/n + (1.0 - 1.0/n)*phi - 2.0*phi*(1.0 - phi)*chi;
}

double bisect(double n, double chi, double xa, double xb)
{
  int     k;
  double  xc, fb, fc;

  k = 0;
  do{
    xc = (xa + xb)/2.0;
    fc = f(n, chi, xc);
    fb = f(n, chi, xb);
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
