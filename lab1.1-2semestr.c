#include <stdio.h>

#define N 10000
int sieve[N] = {0};

int recursive_eratosphere (int i, int size) {
    if (i*i < size) {
        for (int k = i*i; k < size; k+=i) {
        sieve[k]=1;
    }
    return recursive_eratosphere (i+1,size);
    } else {
        return 0;
    }
    
}

int main(int argc, char *argv[])
{
    int size;
    int n = 2;
    printf("Enter the number to which to find prime numbers: ");
    scanf("%d",&size);
    recursive_eratosphere(n, size);
    printf("Prime numbers:\n");
    for (int i = n; i < size; i++) {
        if (sieve[i]==0) {
            printf("%3d", i);    
        }
    }
    
    return 0;
}
