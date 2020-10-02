#include<stdio.h>
#define N 1000000
int main()
{                                                                           
    int n;          
    int temp;
    scanf("%d", &n);
    int mass[N];
    for (int i = 0; i<n; i++) {
        scanf("%d", &mass[i]);
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
        printf("%d ", mass[i]);
    }
    
    
    return 0;
}
                                                                                                      
