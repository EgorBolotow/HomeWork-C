#include <stdio.h>
#include "string.h"

int main(void) {

    char first_plenty[100]; // Первое множество, которое вводят 
    char second_plenty[100]; // Второе множество, которое вводят

    char ASCII_table_first_plenty[127]; // Первая таблица с числовыми кодами
    char ASCII_table_second_plenty[127]; // Вторая таблица с числовыми кодами

    scanf("%99s %99s", first_plenty, second_plenty);

    //  Все символы второго множества помечаем цифрой 1, в второй таблице с числовыми кодами символов

    int length1 = strlen(second_plenty);
    for (int i = 0; i < length1; i++) {
        //int temp = second_plenty[i];
        ASCII_table_second_plenty[second_plenty[i]] = 1;
    }

    // Помечаем цифрой 1 все символы первого множества, в первой таблице с числовыми кодами, которых нет в второй таблице с числовыми кодами

    int length2 = strlen(first_plenty);
    for (int i = 0; i < length2; i++) {
        //int temp2 = second_plenty[i];
        //int temp3 = first_plenty[i];
        if (ASCII_table_second_plenty[second_plenty[i]]==1) {}
        else {ASCII_table_first_plenty[first_plenty[i]] = 1;}
                      
    }

    // Выводим результат

    for (int i = 0; i<128; i++) {
        if (ASCII_table_first_plenty[i] == 1) {
            int result = i;
            printf ("%c", i);
        }      
    }

    printf("\n");

    return 0;
}
// gcc LAB10.c -o l10 && ./l10