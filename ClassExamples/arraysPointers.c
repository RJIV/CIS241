#include <stdlib.h>
#include <stdio.h>

int f1(int x, int y, int z)
{
	int sum = 0;
	x++;
	y++;
	z++;
	sum = x+y+z;
	return sum;
}

void f2(int a[], int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		a[i]++;
	}
}

int main()
{
	int num[] = {1, 2, 3, 4, 5};
	int total = f1(num[0], num[1], num[2]);
	printf("%d %d %d %d\n", num[0], num[1], num[2], total);
	f2(num, 5);
	printf("%d %d %d %d %d\n", num[0], num[1], num[2], num[3], num[4]);
	total = f1(num[0], num[1], num[2]);
	printf("%d %d %d %d\n", num[0], num[1], num[2], total);
}
