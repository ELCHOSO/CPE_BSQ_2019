/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** size of square and corner of square
*/

#include "my.h"

int find_corner_x(int **map, int x_max, int y_max)
{
    int y = 0;
    int x_corner = 0;
    int value = 0;

    for (int x = 0; x != x_max; x++) {
        for (; y != y_max; y++) {
            if (map[x][y] > value) {
                value = map[x][y];
                x_corner = x;
            }
        }
        y = 0;
    }
    return (x_corner);
}

int find_corner_y(int **map, int x_max, int y_max)
{
    int y = 0;
    int y_corner = 0;
    int value = 0;

    for (int x = 0; x != x_max; x++) {
        for (; y != y_max; y++) {
            if (map[x][y] > value) {
                value = map[x][y];
                y_corner = y;
            }
        }
        y = 0;
    }
    return (y_corner);
}

int find_sqr_size(int **map, int x_max, int y_max)
{
    int y = 0;
    int value = 0;

    for (int x = 0; x != x_max; x++) {
        for (; y != y_max; y++) {
            if (map[x][y] > value) {
                value = map[x][y];
            }
        }
        y = 0;
    }
    return (value);
}

t_corner init_corner(int **map, int x_max, int y_max)
{
    t_corner corner;
    corner.x = find_corner_x(map, x_max, y_max);
    corner.y = find_corner_y(map, x_max, y_max);
    corner.size = find_sqr_size(map, x_max, y_max);
    corner.x_beg = corner.x - corner.size;
    corner.y_beg = corner.y - corner.size;
    return (corner);
}

int is_sqr(int x, int beginning, int end)
{
    if (beginning < x && x <= end)
        return (1);
    return (0);
}
