#include <stdio.h>
#include <math.h>
#define N 1000001

int main()
{

    int mass[N] = {0};
    int n;
    scanf("%d", &n);
    
    for (int i = 2; i*i<N;++i) {
        if (mass[i] == 0) {
            for (int j = i*i; j<N; j+=i) {
                mass[j] = 1;
            }
        }
    }
    
    for (int i = 2; i < n; ++i) {
        if (mass[i] == 0) {
            printf("%3d", i);
        }
    }
    

    return 0;
}
