#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, d, e, f, x, y = 0;
    printf("Введите первую дату: ");
    scanf ("%d %d %d", &a, &b , &c);
    printf("Введите вторую дату: ");
    scanf ("%d %d %d", &d, &e , &f);
    
    int m1 = 31;
    int m2 = 28;
    int m3 = 31;
    int m4 = 30;
    int m5 = 31;
    int m6 = 30;
    int m7 = 31;
    int m8 = 31;
    int m9 = 30;
    int m10 = 31;
    int m11 = 30;
    int m12 = 31;
    
    if (b == 1) { x = a; }
    else if (b == 2) { x = m1 + a; }
    else if (b == 3) { x = m1 + m2 + a; }
    else if (b == 4) { x = m1 + m2 + m3 + a; }
    else if (b == 5) { x = m1 + m2 + m3 + m4 + a; }
    else if (b == 6) { x = m1 + m2 + m3 + m4 + m5 + a; }
    else if (b == 7) { x = m1 + m2 + m3 + m4 + m5 + m6 + a; }
    else if (b == 8) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + a; }
    else if (b == 9) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + a; }
    else if (b == 10) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + a; }
    else if (b == 11) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + a; }
    else if (b == 12) { x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + a; }
    
    if (e == 1) { y = d + y; }
    else if (e == 2) { y = m1 + d + y; }
    else if (e == 3) { y = m1 + m2 + d + y; }
    else if (e == 4) { y = m1 + m2 + m3 + d + y; }
    else if (e == 5) { y = m1 + m2 + m3 + m4 + d + y; }
    else if (e == 6) { y = m1 + m2 + m3 + m4 + m5 + d + y; }
    else if (e == 7) { y = m1 + m2 + m3 + m4 + m5 + m6 + d + y; }
    else if (e == 8) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + d + y; }
    else if (e == 9) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + d + y; }
    else if (e == 10) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + d + y; }
    else if (e == 11) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + d + y; }
    else if (e == 12) { y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + d + y; }
    
    int days = abs (y-x);
    int days2 = abs ((f - c) + (y - x));
    
    if (c == f) {
        printf ("Количество дней между этими датами: %d", days);
    } else {
        printf ("Количество дней между двумя датами: %d", days2);
    }
    
    return 0;
}
