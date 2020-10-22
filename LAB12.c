#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char number[60];
char result_number[60];
unsigned char start_number_system;
unsigned char end_number_system;
unsigned char k;
char p_str = '0';
int result;

int r;

char digits[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
unsigned char table[256];

int update_pow (unsigned char a, int b);
int number_figures (char *str);
void to_10_number_system ();
void from_10_to_other();


int main(void) {


    printf("Введите исходную систему счисления: ");
    scanf("%hhu", &start_number_system);
    printf("\n");

    printf("Введите конечную систему счисления: ");
    scanf("%hhu", &end_number_system);
    printf("\n");

    printf("Введите кол-во знаков после запятой: ");
    scanf("%hhu", &k);
    printf("\n");

    printf("Введите число: ");
    scanf("%s", number);

    to_10_number_system();
    from_10_to_other();
    printf("%s", number);


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

int number_figures (char *str) {
    int counter = 0;
    for (int i = 0; str[i] != '\0' ; i++) {
        counter++;
    }
    return counter;
}

void to_10_number_system () {
    int n = number_figures(number) - 1;
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
    for (int i; num >= end_number_system; i++) {
        printf ("%d\n", num%end_number_system);
        if ((num % end_number_system) >= 10) {

            number[i] = (num % end_number_system) - 10 + 'A';
            printf ("%c\n", (num % end_number_system) - 10 + 'A');

        } else {
            number[i] = (num % end_number_system) + '0';
        }
        num /= end_number_system;

    }
    printf ("%d\n", num);
    number[i] = num + '0';

}

// gcc -o l12 lab12.c && ./l12
