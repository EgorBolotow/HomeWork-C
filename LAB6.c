#include <stdio.h>
#include <math.h>

int isLeapYear (int year) {

    if (year%4!=0) {
        return 0;
    } else {
        if (y%100 == 0 && y%400 != 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

int main () {

    int day1;
    int day2;
    int month1;
    int month2;
    int year1;
    int year2;

    printf("Введите первую дату: ");
    scanf ("%d %d %d", &day1, &month1, &year1 );
    printf("Введите вторую дату: ");
    scanf ("%d %d %d", &day2, &month2, &year2);

    if (isLeapYear(year1)) {
        unsigned char leapMonths1 [12] = {
                31, // January
                29, // February
                31, // March
                30, // April
                31, // May
                30, // June
                31, // July
                31, // August
                30, // September
                31, // October
                30, // November
                31  // December
        } else {
            unsigned char commonMonths1 [12] = {
                    31, // January
                    28, // February
                    31, // March
                    30, // April
                    31, // May
                    30, // June
                    31, // July
                    31, // August
                    30, // September
                    31, // October
                    30, // November
                    31  // December
            }
        }
    }

    if (isLeapYear(year2)) {
        unsigned char leapMonths2 [12] = {
                31, // January
                29, // February
                31, // March
                30, // April
                31, // May
                30, // June
                31, // July
                31, // August
                30, // September
                31, // October
                30, // November
                31  // December
        } else {
            unsigned char commonMonths2 [12] = {
                    31, // January
                    28, // February
                    31, // March
                    30, // April
                    31, // May
                    30, // June
                    31, // July
                    31, // August
                    30, // September
                    31, // October
                    30, // November
                    31  // December
            }
        }



    
    return 0;
}
