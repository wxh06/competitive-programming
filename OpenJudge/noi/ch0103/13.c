#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	n = (n % 10) * 100 + n / 10 % 10 *10 + n / 100;
	printf("%03d", n);
	return 0;
}
