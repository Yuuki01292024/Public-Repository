﻿#include <stdio.h>
#include <math.h>

double f(double, double);

int main(void)
{
  int     i = 0, n;
  double  t_max, dt;
  double  s;
  double  t0, t1, x0, x1;

  n     = 20;
  t_max = M_PI;
  dt    = t_max/(double)n;
  x0    = 1.0;
  t0    = 0.0;
  do{
    //printf("%e %e\n", t0, x0);
    s  = f(t0, x0);
    x1 = x0 + s*dt;
    t1 = t0 + dt;
    x0 = x1;
    t0 = t1;
  }while( ++i < n );
  printf("%e %e %e %e\n", t0, x0, dt, fabs(x0 - exp(t0)));

  return 0;
}

double f(double t, double x)
{
  return  exp(t);
}
