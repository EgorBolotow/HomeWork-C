#include "stdio.h"
#include "math.h"

int main(int argc, char** argv) {
	double a, b, c;

	printf("Please enter an `a` value: ");
	scanf("%lf", &a);
	printf("Please enter a  `b` value: ");
	scanf("%lf", &b);
	printf("Please enter a  `c` value: ");
	scanf("%lf", &c);

	if (a==0) {
        double x = -c/b;
        printf("x = %.2lf \n", x);

	} else {
        double d = b*b - 4 * a * c;

        if (d>0) {
            double x1 = (-b + sqrt(d))/(2*a);
            double x2 = (-b - sqrt(d))/(2*a);
            printf("x1 = %.2lf \nx2 = %.2lf",x1,x2);

        } else if (d==0) {
            double x = -b/(2*a);
            printf("x = %.2lf",x);
        }
    }
	return 0;
}


