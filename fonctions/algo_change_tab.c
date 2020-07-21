/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** algo qui va chercher le grand carré
*/

#include "my.h"

int min(int left, int top, int corner)
{
    int result = left;

    if (top < result)
        result = top;
    if (corner < result)
        result = corner;
    return (result);
}

int **algo_change_tab(int **m, int x_max, int y_max)
{
    int y = 1;

    for (int x = 1; x != x_max; x++) {
        for (; y != y_max; y++) {
            if (m[x][y] == 1)
                m[x][y] = min(m[x - 1][y], m[x][y - 1], m[x - 1][y - 1]) + 1;
        }
        y = 0;
    }
    return (m);
}
