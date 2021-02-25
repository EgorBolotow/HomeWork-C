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
        unsigned char temp = buf[i];
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
    size_t b;
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

    clock_t start = clock();

    while (1) {
        b = fread(buffer,sizeof(char),100,fp);
        if (b==0) {
            break;
        }
        counter += func(buffer,b);
    }

    clock_t end = clock();

    double time = (double)(end - start)/(double)(CLOCKS_PER_SEC/1000);

    printf("\n");
    printf("%d", counter);
    printf("\n");
    printf("Время выполнения: %lf", time);

    return 0;
}
