#include <stdio.h>
#include <stdint.h>

void swap(void * a, void * b, size_t len) {
    uint8_t * p = a, * q = b, tmp;
    for(len /= 2; len != 0; len--) {
        uint8_t t = *p;
        *p = *q;
        *q = t;
        a++;
        b--;
    }
}

int compare (void *a, void *b) {
    if (*(int*)a>*(int*)b) {
        return 1;
    } else if (*(int*)a==*(int*)b){
        return 0;
    } else {
        return -1;
    }   
}

void cocktail_sort (void *array, int n,size_t size, int (*fun)(void*, void*)) {
    char swapped = 1;
    int start = 0;
    int end = n - 1;
    
    while (swapped) {
        swapped = 0;
        
        for (int i = start; i < end; ++i) {
            if (0 > fun((void*)(((uint8_t*)array) + size * i), (void*)(((uint8_t*)array) + size * i + size))) {
                swap((void*)(((uint8_t*)array) + size * i), (void*)(((uint8_t*)array) + size * i + size), sizeof(size));
                swapped = 1;
            }
        }
        
        if (!swapped) {
            break;    
        }
        
        swapped = 0;
        
        --end;
        
        for (int i = end - 1; i >= start; --i) {
            if (0 > fun((void*)(((uint8_t*)array) + size * i), (void*)(((uint8_t*)array) + size * i + size))) {
                swap((void*)(((uint8_t*)array) + size * i), (void*)(((uint8_t*)array) + size * i + size), sizeof(size));
                swapped = 1;
            }
        }
        
        ++start;
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = { 5, 1, 4, 2, 8, 0, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    printArray(a,n);
    cocktail_sort(a, n, sizeof(int), compare);
    printf("Sorted array:\n");
    printArray(a,n);
    return 0;
}
