#include<stdio.h>
int main()
{
	int count, age, i, sum = 0;
	float aver;
	scanf("%d", &count);
	for(i = 0; i < count; ++i)
	{
		scanf("%d", &age);
		sum += age;
	}
	aver = 1.0 * sum / count;
	printf("%.2f", aver);
	return 0;
}
