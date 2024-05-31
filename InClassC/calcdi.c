#include <stdio.h>

int main(void)
{
  int i;

  i = 2;
  printf("i=%d \n", i);

  i = i + 3;
  printf("i=%d \n", i);

  i /= 3;
  printf("i=%d \n", i);

  return 0;
}
