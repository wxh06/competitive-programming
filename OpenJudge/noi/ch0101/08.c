#include<stdio.h>
int main()
{
	char c;
	scanf("%c", &c);
	int i, j;
	for (i = 1; i <= 5; i += 2)
	{
		for (j = 0; j < (5 - i) / 2; ++j)
			printf(" ");
		for (j = 0; j < i; ++j)
			printf("%c", c);
		printf("\n");
	}
}
