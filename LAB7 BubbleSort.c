#include<stdio.h>
#define N 1000000
int main()
{                                                                           
    int n;          
    float temp;
    scanf("%d", &n);
    float mass[N];
    for (int i = 0; i<n; i++) {
        scanf("%f", &mass[i]);
    }
    
    for (int i = 0; i<n;i++){
        for (int j = 0; j<n-1-i; j++) {
            if (mass[j]>mass[j+1]) {
                temp = mass[j];             
                mass[j] = mass[j+1];
                mass[j+1] = temp;
            }    
        }   
    }
                                                                                                                                                        
    for (int i = 0; i<n; i++) {
        printf("%f ", mass[i]);
    }
    
    
    return 0;
}
