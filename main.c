#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char**argv)
{
    float a,b,c,d,x1,x2;
    printf("Input value a: ");
    scanf("%f", &a);
    printf("Input value b: ");
    scanf("%f", &b);
    printf("Input value c: ");
    scanf("%f", &c);
    d = b*b-4*a*c;
    if (d>0) {
        x1 = (-b + sqrt(d))/2*a;
        x2 = (-b - sqrt(d))/2*a;
        float dec1,dec2;
        float frac1 = modf(x1,&dec1);
        float frac2 = modf(x2,&dec2);
        if (fabs(frac1)<0.01 && fabs(frac2)<0.01) {
            printf("x1 = %d \nx2 = %d",(int)dec1,(int)dec2);
        } else {
            printf("x1 = %.2f \nx2 = %.2f",x1,x2);
        }
    } else if (d=0) {
        x1 = (-b + sqrt(d))/2;
        printf("x1 = %.2f\n",x1);
    } else {

    }
    return 0;
}
