#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
 
char number[60];
char result_number[60];
unsigned char start_number_system;
unsigned char end_number_system;
unsigned char k;
int result;
int result2;
 

int update_pow (unsigned char a, int b);
int number_of_figures (char *str);
int decimal_number_of_figures(char *str);
void to_10_number_system ();
void from_10_to_other();
void decimal_to_10_number_system();
int negative_pow (int a, int b);
 
 
int main(void) {
 
 
    printf("Введите исходную систему счисления: ");
    scanf("%hhu", &start_number_system);
    printf("\n");
 
    printf("Введите конечную систему счисления: ");
    scanf("%hhu", &end_number_system);
    printf("\n");
 
    printf("Введите кол-во знаков после запятой, если число целое, то 0: ");
    scanf("%hhu", &k);
    printf("\n");
 
    printf("Введите число: ");
    scanf("%s", number);
 
    if (k==0) {
        to_10_number_system();
        from_10_to_other();
        printf("%s", result_number);
    } else {
        decimal_to_10_number_system();
    }
 
    return 0;
}
 
int update_pow (unsigned char a, int b) {
    unsigned int result = 1;
    if (b == 0) {
        return result;
    } else {
        for (int i = 0; i<b; i++) {
            result *= a;
        }
        return result;
    }
}
 
int negative_pow (int a, int b) {
    int res = 1;
    int t = abs(b);
    res = 1 / (update_pow(a, t));
    return res;
}
 
int number_of_figures (char *str) {
    int counter = 0;
    for (int i = 0; str[i] != '\0' ; i++) {
        counter++;
    }
    return counter;
}
 
int decimal_number_of_figures(char *str) {
    int counter = 0;
    for (int i = 0; str[i] != 46 ; i++) {
        if (str[i] == 46) {
            break;
        } else {
            counter++;
        }
    }
    return counter;
}
 
void to_10_number_system () {
    int n = number_of_figures(number) - 1;
    for (int i = 0; number[i] != '\0'; i++) {
        int buff;
        if ((number[i] >= 65) && (number[i] <= 70)) {
            buff = number[i] - '7';
        } else if ((number[i] >= 48) && (number[i] <= 57)) {
            buff = number[i] - '0';
        }
        result = result + (buff * update_pow(start_number_system, n));
        n--;
    }
 
    sprintf( number, "%d\n", result );
 
}
 
void from_10_to_other () {
    int num = atoi(number);
    int i = 0;
    for (i = 0; num >= end_number_system; i++) {
        if ((num % end_number_system) >= 10) {
 
            number[i] = (num % end_number_system) - 10 + 'A';
 
        } else {
            number[i] = (num % end_number_system) + '0';
        }
        num /= end_number_system;
 
    }
 
    number[i] = num + '0';
 
    int p = (strlen(number)) - 1;
    for (int i = 0; p!= -1; i++) {
        result_number[i] = number[p];
        p--;
    }
}
 
void decimal_to_10_number_system() {
    int n = decimal_number_of_figures(number) - 1;
    int result = 0;
    int i;
    for (i = 0; number[i] != '.'; i++) {
        if (number[i] == '.') {
            break;
        } else {
            int buff;
            if ((number[i] >= 65) && (number[i] <= 70)) {
                buff = number[i] - '7';
            } else if ((number[i] >= 48) && (number[i] <= 57)) {
                buff = number[i] - '0';
            }
            result = result + (buff * update_pow(start_number_system, n));
            n--;
        }
    }
 
    printf("%d \n", result);
    
}
