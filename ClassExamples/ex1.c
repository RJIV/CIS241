#include <stdio.h>

int main()
{
	int a[5];
	int i = 0;
	int sum = 0;
	a[0]=a[1]=a[2]=a[3]=a[4]=2;
	for(i=0;i<2;i++)
		sum+=a[i];
	if (sum==4)
		printf("sum is %d\n", sum);
	return 0;
}

