  
#include <stdio.h>
#include "math.h"


int sum = 0;
int count = 0;
const double e = 0.0001;
double x = 0.7;

int factorial (int n)
{
  if (n == 0 || n == 1) {
    return 1;
} else {
    return n * factorial(n - 1);
  }
}

double taylor_series (double x, int n) {

  double buffer = (pow(x,2*n))/ (factorial(2*n));
    if (fabs(buffer) > e) {
      return buffer + taylor_series(x,n+1);
    }

}

int main()
{

  printf ("My result: %.4f",taylor_series(x,0));
  printf("\n");
  printf("Library result: %.4f",cosh(x));
  return 0;
}
