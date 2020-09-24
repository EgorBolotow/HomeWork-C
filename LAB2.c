#include<stdio.h>
#include <math.h>
 
int prime(int limit)
{
    int t;
    int i;
    int count=0;
    int flag;
    
    if (limit<=0);
    else
    {   
        for(t=2 ; t<=limit ; t++)
        {
            flag=1;
            for (i=2; i*i<=t ;i++)
            {
                if (t%i==0) 
                { 
                  flag=0;
                  break;
                }
            }
            if (flag)
            {
                printf("%d ", t);
                count++;
            }
        }
    
    
    }
    return count; 
}
 
int main (int argc, char** argv)
{
    int a;
    printf("Input limit:");
    scanf("%d", &a);
    prime(a);
    return 0;
}
