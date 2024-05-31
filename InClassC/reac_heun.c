#include <stdio.h>
#include <math.h>

double f1(double, double, double, double);
double f2(double, double, double, double);
double f3(double, double, double, double);

double k1, k2;

int main(void)
{

  printf("k1: ");
  scanf("%lf", &k1);

  printf("k2: ");
  scanf("%lf", &k2);
  int     i = 0, n;
  double  t_max, dt;
  double  s11, s21, s31, s12, s22, s32;
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
    s11 = f1(t0, A0, B0, C0);
    s21 = f2(t0, A0, B0, C0);
    s31 = f3(t0, A0, B0, C0);
    s12 = f1(t0 + dt, A0 + s11*dt, B0 + s21*dt, C0 + s31*dt);
    s22 = f2(t0 + dt, A0 + s11*dt, B0 + s21*dt, C0 + s31*dt);
    s32 = f3(t0 + dt, A0 + s11*dt, B0 + s21*dt, C0 + s31*dt);
    A1 = A0 + (s11 + s12)*dt/2;
    B1 = B0 + (s21 + s22)*dt/2;
    C1 = C0 + (s31 + s32)*dt/2;
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
