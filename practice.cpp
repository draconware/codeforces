#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n=0,l=0,a,b;
    //printf("Enter two positive numbers");
    scanf("%d %d", &a, &b);
    i = a-b;
    while(i!=0)
    {
        i=i/10;
        n++;
    }
    int k=a-b-1;
    int m=k;
    while(k!=0)
    {
        k=k/10;
        l++;
    }
    if(a==b||a-b==1)
    {
        printf("2");
    }
    else
    {
        if(n==l)
            printf("%d",m);
        else
            printf("%d",m+2);
    }
}
