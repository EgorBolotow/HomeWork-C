#include <stdio.h>
#include "string.h"

int main(void) {

    char first_plenty[100]; // Первое множество, которое вводят 
    char second_plenty[100]; // Второе множество, которое вводят

    char ASCII_table_first_plenty[128] = {0}; // Первая таблица с числовыми кодами
    char ASCII_table_second_plenty[128] = {0}; // Вторая таблица с числовыми кодами

    scanf("%99s %99s", first_plenty, second_plenty);

    //  Все символы второго множества помечаем цифрой 1, в второй таблице с числовыми кодами символов

    int length = strlen(second_plenty);
    for (int i = 0; i < length; i++) {
        ASCII_table_second_plenty[second_plenty[i]] = 1;
    }

    // Помечаем цифрой 1 все символы первого множества, в первой таблице с числовыми кодами, которых нет в второй таблице с числовыми кодами

    length = strlen(first_plenty);
    for (int i = 0; i < length; i++) {
        if (!ASCII_table_second_plenty[first_plenty[i]]) {
            ASCII_table_first_plenty[first_plenty[i]] = 1;
        }
                      
    }

    // Выводим результат

    for (int i = 0; i<128; i++) {
        if (ASCII_table_first_plenty[i]) {
            printf ("%c", i);
        }      
    } 

    printf("\n");

    return 0;
}
