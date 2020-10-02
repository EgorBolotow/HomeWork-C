#include<stdio.h>

int NOD (int a, int b) {
    if (a == b) {
        return a;
    }

    if (a < b) {
        return NOD (a, b - a);
    }
    else {
        return NOD (a - b, b);
    }
}


int NOK (int n1, int n2) {
    return n1 * n2 / NOD (n1, n2);
}

int main () {
    int number1;
    int number2;
    scanf("%d %d", &number1, &number2);
    int resoult = NOK(number1, number2);
    printf ("%d", resoult);
    return 0;       
}
