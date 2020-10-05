#include <stdio.h>
#include <stdlib.h>

unsigned char leapYearMonths [12] = {
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
};

unsigned char commonYearMonths [12] = {
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
};

//                Функция пороверяет является ли год високосным

char isLeapYear (unsigned int year) {

    if (year%4!=0) {
        return 0;
    } else {
        if (year%100 == 0 && year%400 != 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

//                Функция проверяет введенные числа на корректность

void checkValues ( unsigned d1, unsigned d2, unsigned m1, unsigned m2, unsigned y1, unsigned y2) {

    if (d1<=0 || d2<=0 || m1<=0 || m2<=0 || y1<=0 || y2<=0) {
        printf("Вы ввели отрицательные числа или нулевые числа!");
        exit(0);
    }

    if ((1<=m1 && m1 <=12) && (1<=m2 && m2 <=12)) {}
    else {
        printf("Вы ввели некорректное значение!");
        exit(0);
    }

    if ((1<=d1 && d1<=31) && (1<=d2 && d2<=31)) {}
    else {
        printf("Вы ввели некорректное значение!");
        exit(0);
    }

    if (isLeapYear(y1)) {
        if (m1==2) {
            if (d1>29) {
                printf("Вы ввели некорректное значение!");
                exit(0);
            }
        }
    } else {
        if (m1==2) {
            if (d1>28) {
                printf("Вы ввели некорректное значение!");
                exit(0);
            }
        }
    }

    if (isLeapYear(y2)) {
        if (m2==2) {
            if (d2>=29) {
                printf("Вы ввели некорректное значение!");
                exit(0);
            }
        }

    } else {
        if (m2==2) {
            if (d2>=28) {
                printf("Вы ввели некорректное значение!");
                exit(0);
            }
        }
    }
}


int numberDaysinYear (year) {

}


int main () {

    unsigned int day1;
    unsigned int day2;
    unsigned int month1;
    unsigned int month2;
    unsigned int year1;
    unsigned int year2;

    printf("Введите первую дату: ");
    scanf ("%d %d %d", &day1, &month1, &year1 );
    printf("Введите вторую дату: ");
    scanf ("%d %d %d", &day2, &month2, &year2);

    checkValues(day1, day2, month1, month2, year1, year2);



    return 0;
}

