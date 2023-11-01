#include <stdio.h>
int main()
{
	int h, w, a, i, j;
	char c;
	scanf("%d %d %c %d", &h, &w, &c, &a);
	if (a)
		for (i = 0; i < h; ++i)
		{
			for (j = 0; j < w; ++j)
				printf("%c", c);
			printf("\n");
		}
	else
	{
		for (i = 1; i <= h; ++i)
		{
			if (i == 1 || i == h)
				for (j = 1; j <= w; ++j)
					printf("%c", c);
			else
			{
				printf("%c", c);
				for (j = 0; j < w - 2; ++j)
					printf(" ");
				printf("%c", c);
			}
			printf("\n");
		}
	}
	return 0;
}
