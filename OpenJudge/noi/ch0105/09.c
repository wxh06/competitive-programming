#include<stdio.h>
int main()
{
	int from, to, i, sum = 0;
	scanf("%d %d", &from, &to);
	for(i = from; i <= to; i++)
		if(i % 2 == 1)
			sum += i;
	printf("%d", sum);
	return 0;
}
