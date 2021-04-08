#include <stdio.h>
#include <stdint.h>

void swap(void* p1, void* p2, size_t size) {
    uint8_t* u1 = (uint8_t*) p1;
    uint8_t* u2 = (uint8_t*) p2;
    for(size_t i = 0; i != size; i++) {
        *u1 ^= *u2;
        *u2 ^= *u1;
        *u1 ^= *u2;
        u1++;
        u2++;
    }
}

int compare (void *a, void *b) {
    if (*(int*)a>*(int*)b) {
        return -1;
    } else if (*(int*)a==*(int*)b){
        return 1;
    } else {
        return 1;
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

int main() {
    int a[] = { 5, 1, 4, 2, 9, 8, 10, 0 , 2 };
    int n = sizeof(a) / sizeof(a[0]);
    printArray(a,n);
    cocktail_sort(a, n, sizeof(int), compare);
    printf("Sorted array:\n");
    printArray(a,n);
    return 0;
}
