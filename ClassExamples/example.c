#include<stdio.h>
int func(int n)
{
        int i, s=0;
        for (i=0;i<n;i++)
        {
                s+=i;
        }
        return s;
}

int main()
{
        int i,j=0;
        j++;
        j=func(5);
        printf("j=%d\n",j);
        return 1;
}

