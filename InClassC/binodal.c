#include <stdio.h>
#include <math.h>

int    k_max = 50;
double eps   = 1.0e-10;
double dx    = 1.0e-2;
double dy    = 1.0e-2;

double f1(double, double, double, double);
double f2(double, double, double, double);
double bisect(double, double, double);

int main(void)
{
  int     k = 0;
  double  xa, xb, xc, ya, yb, yc, fa, fb, fc, n, chi, dchi;
  
  n = 3.0;
  chi = 0.0;
  dchi = 0.01;

  do{
  chi = chi + dchi;
  xa  = eps;
  xb  = xa + dx;
    do{ 
      ya = bisect(n, chi, xa);
      yb = bisect(n, chi, xb);
      if( ya > 0.0 && yb > 0.0 ){
        fa = f2(n, chi, xa, ya);
        fb = f2(n, chi, xb, yb);
        if( fa*fb < 0.0 ){
  	  k = 0;
	  do{
	    xc = (xa + xb)/2.0;
	    yc = bisect(n, chi, xc);
	    fc = f2(n, chi, xc, yc);
	    if( k >= k_max ){
	      printf("PROGRAM ERROR\n");
	      break;
	    }
	    if( fb*fc > 0.0 ){
	      xb = xc;
	    }
	    else{
	      xa = xc;
	    }
	    k++;
  	  }while( fabs(xb - xa) > eps );
	  printf("%f %f %f \n", chi, xc, yc);
	}
      }
      xa += dx;
      xb += dx;
  }while( xb < 1.0 );


  }while(chi < 2.0) ;
  return  0;
}

double f1(double n, double chi, double x, double y)
{
  double  dmux, dmuy;
  
  dmux = log(1.0 - x) + (1.0 - (1.0/n))*x + chi*x*x;
  dmuy = log(1.0 - y) + (1.0 - (1.0/n))*y + chi*y*y;
  
  return  dmux - dmuy;
}

double f2(double n, double chi, double x, double y)
{
  double  dmux, dmuy;
  
  dmux = log(x) - (n - 1.0)*(1.0 - x) + n*chi*(1.0 - x)*(1.0 - x);
  dmuy = log(y) - (n - 1.0)*(1.0 - y) + n*chi*(1.0 - y)*(1.0 - y);
  
  return  dmux - dmuy;
}

double bisect(double n, double chi, double x)
{
  int     k;
  double  ya, yb, yc, fa, fb, fc;
  
  yb = 1.0 - eps;
  ya = yb - dy;
  do{
    fa = f1(n, chi, x, ya);
    fb = f1(n, chi, x, yb);
    if( fa*fb < 0.0 ){
      yc = (ya + yb)/2.0;
      fb = f1(n, chi, x, yb);
      fc = f1(n, chi, x, yc);
      k  = 0;
      do{
	if( k >= k_max ){
	  printf("PROGRAM ERROR\n");
	  break;
	}
	if( fb*fc > 0 ){
	  yb = yc;
	}
	else{
	  ya = yc;
	}
	yc = (ya + yb)/2.0;
	fc = f1(n, chi, x, yc);
	k++;
      }while( fabs(yb - ya) > eps );
      return  yc;
    }
    yb -= dy;
    ya -= dy;
    }while( ya > x );
  
  return  -1;
}
