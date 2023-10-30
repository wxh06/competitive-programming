#include <stdio.h>
#include <stdlib.h>

void main()
{
    char grid[2][3][3];
    for (unsigned short i = 0; i < 2; i++)
        for (unsigned short j = 0; j < 3; j++)
        {
            for (unsigned short k = 0; k < 3; k++)
                scanf("%c", &grid[i][j][k]);
            scanf("\n");
        }
    unsigned short green = 0, yellow = 0, count[2][26] = {};
    for (unsigned short i = 0; i < 3; i++)
        for (unsigned short j = 0; j < 3; j++)
            if (grid[0][i][j] == grid[1][i][j])
                green++;
            else
            {
                count[0][grid[0][i][j] - 'A']++;
                count[1][grid[1][i][j] - 'A']++;
            }
    for (unsigned short i = 0; i < 26; i++)
        yellow += count[0][i] < count[1][i] ? count[0][i] : count[1][i];
    printf("%hu\n%hu\n", green, yellow);
    exit(0);
}
