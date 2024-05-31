#include <stdio.h>
#include <math.h>

double f1(double, double, double, double);
double f2(double, double, double, double);
double f3(double, double, double, double);

double k1 = 10.0;
double k2 = 1.0;

int main(void)
{
  int     i = 0, n;
  double  t_max, dt;
  double  s1, s2, s3;
  double  t0, t1, A0, A1, B0, B1, C0, C1;
  
  n     = 100;
  t_max = 1.0;
  dt    = t_max/(double)n;
  t0    = 0.0;
  A0    = 1.0;
  B0    = 0.0;
  C0    = 0.0;
  do{
    printf("%e %e %e %e\n", t0, A0, B0, C0);
    s1 = f1(t0, A0, B0, C0);
    s2 = f2(t0, A0, B0, C0);
    s3 = f3(t0, A0, B0, C0);
    A1 = A0 + s1*dt;
    B1 = B0 + s2*dt;
    C1 = C0 + s3*dt;
    t1 = t0 + dt;
    A0 = A1;
    B0 = B1;
    C0 = C1;
    t0 = t1;
  }while( ++i < n );
  printf("%e %e %e %e\n", t0, A0, B0, C0);

  return  0;
}

double f1(double t, double A, double B, double C)
{
  return  -k1*A;
}

double f2(double t, double A, double B, double C)
{
  return  k1*A - k2*B;
}

double f3(double t, double A, double B, double C)
{
  return  k2*B;
}
