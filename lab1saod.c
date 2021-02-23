#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int func (char *buf, int s) {
    int c = 0;
    int count = 0;
    int count1 = 0;
    for (int i = 0; i<s; i++) {
        int temp = buf[i];
        while (temp) {
            if (temp%2==0) {
                count++;
            }
            temp = temp / 2;
            count1++;
        }
        c+=(8-count1) + count;
        count=0;
        count1=0;
    }
    return c;
}

char buffer[100];

int main(int argc, char *argv[])
{
    int a;
    int counter = 0;
    setlocale(LC_ALL, "Russian");
    char *file_name = argv[1];
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Не удалось открыть файл");
        return 0;
    } else {
        printf("Файл был открыт");
    }

    while (1) {
        int b = fread(buffer,sizeof(char),100,fp);
        if (b==0) {
            break;
        }
        int buf_counter = func(buffer,b);
        counter += buf_counter;
    }

    printf("\n");
    printf("%d", counter);

    return 0;
}
