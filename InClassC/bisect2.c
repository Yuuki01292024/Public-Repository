#include <stdio.h>
#include <math.h>

#define eps   1.0e-5
#define k_max 50

double f1(double, double);
double f2(double, double);
double bisect(double);

int main(void)
{
  int     k = 0;
  double  a, b, c, ya, yb, yc, fa, fb, fc;

  a = 0.1;
  b = a + 0.1;
  do{
    ya = bisect(a);
    yb = bisect(b);
    fa = f2(a, ya);
    fb = f2(b, yb);
    if( fa*fb < 0.0 ){
      ya = bisect(a);
      fa = f2(a, ya);
      do{
	k++;
	c  = (a + b)/2.0;
	yc = bisect(c);
	fc = f2(c, yc);
	printf("%d %e %e\n", k, c, yc);
	if( k >= k_max ){
	  printf("PROGRAM ERROR\n");
	  break;
	}
	if( fa*fc < 0.0 ){
	  b = c;
	}
	else{
	  a = c;
	}
      }while( fabs(b - a) > eps );
    }
    a += 0.1;
    b += 0.1;
  }while( b < 1.0 );

  return  0;
}

double f1(double x, double y)
{
  return  y - x*x;
}

double f2(double x, double y)
{
  return  x*x + y*y - 1.0;
}

double bisect(double x)
{
  int     k;
  double  a, b, c, fb, fc;

  a  = 0.01;
  b  = 0.99;
  c  = (a + b)/2.0;
  fb = f1(x, b);
  fc = f1(x, c);
  k  = 0;
  do{
    if( fb*fc > 0 ){
      b = c;
    }
    else{
      a = c;
    }
    c  = (a + b)/2.0;
    fc = f1(x, c);
    k++;
  }while( fabs(fc) > eps && k < k_max );

  return  c;
}
