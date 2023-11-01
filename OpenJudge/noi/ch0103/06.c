#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%.3f%%", (float)b / (float)a * 100.0);
	return 0;
}
