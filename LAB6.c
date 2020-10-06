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
    }                printf("Вы ввели некорректное значение!");
74
                exit(0);
75
            }
76
        }
77
    } else {
78
        if (m1==2) {
79
            if (d1>28) {
80
                printf("Вы ввели некорректное значение!");
81
                exit(0);
82
            }
83
        }
84
    }
85
​
86
    if (isLeapYear(y2)) {
87
        if (m2==2) {
88
            if (d2>=29) {
89
                printf("Вы ввели некорректное значение!");
90
                exit(0);
91
            }
92
        }
93
​
94
    } else {
95
        if (m2==2) {
96
            if (d2>=28) {
97
                printf("Вы ввели некорректное значение!");
98
                exit(0);
99
            }
100
        }
101
    }
102
}
103
​
104
​
105
int numberDaysinYear (year) {
106
​
107
}
108
​
109
​
110
int main () {
111
​
112
    unsigned int day1;
113
    unsigned int day2;
114
    unsigned int month1;
115
    unsigned int month2;
116
    unsigned int year1;
117
    unsigned int year2;
118
​
119
    printf("Введите первую дату: ");
120
    scanf ("%d %d %d", &day1, &month1, &year1 );
121
    printf("Введите вторую дату: ");
122
    scanf ("%d %d %d", &day2, &month2, &year2);
123
​
124
    checkValues(day1, day2, month1, month2, year1, year2);
125
​
126
​
127
​
128
    return 0;
129
}
130

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

int numberDaysinYear (year, month ,day) {
    int days = 0;
    int resultDays = 0;
    if (isLeapYear(year) ) {
        for (int i = 0; i<=month - 1 ; i++) {
            days += leapYearMonths[i];
        }
        days += day;
        resultDays = 366 - days;
        return resultDays;
    }

    else {
        for (int i = 0; i<=month - 1 ; i++) {
            days += commonYearMonths[i];
        }
        days += day;
        resultDays = 365 - days;
        return resultDays;
    }
}


int main (int argc, char **argv) {

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

    unsigned int result = 0;

    if (year1 > year2) {
        for (int j = year2; j<=year1; j++) {
            if (j == year2) {
                result += numberDaysinYear(year2, month2, day2);
            } else if (j == year1) {
                result += numberDaysinYear(year1, month1, day1);
            } else {
                if (isLeapYear(j)) {
                    result += 366;
                } else {
                    result += 365;
                }
            }
        }
    } else {
        for (int j = year1; j<=year2; j++) {
            if (j == year1) {
                result += numberDaysinYear(year1, month1, day1);
            } else if (j == year2) {
                result += numberDaysinYear(year2, month2, day2);
            } else {
                if (isLeapYear(j)) {
                    result += 366;
                } else {
                    result += 365;
                }
            }
        }
    }

    printf("%d", result);

    return 0;
}

