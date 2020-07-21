/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** main
*/

#include "my.h"

char *put_map_in_str(int **map, int x_max, int y_max, t_corner c)
{
    int y = 0;
    int size = x_max * y_max + x_max + 1;
    char *str = malloc(sizeof(char) * size);
    int i = 0;

    for (int x = 0; x != x_max; x++, i++) {
        for (; y != y_max; y++, i++) {
            if (is_sqr(x, c.x_beg, c.x) == 1 && is_sqr(y, c.y_beg, c.y) == 1)
                str[i] = 'x';
            else if (map[x][y] == 0)
                str[i] = 'o';
            else
                str[i] = '.';
        }
        y = 0;
        str[i] = '\n';
    }
    str[i] = '\0';
    return (str);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    write(1, str, i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void one_column(char *map)
{
    int stock = 1;
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == '.' && stock == 1) {
            my_putchar('x');
            i++;
            stock--;
        }
        if (map[i] != '\0')
            my_putchar(map[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int x_max = get_line(av[1]);
    int y_max = get_column(av[1]);
    int **map;
    int **calculated_map;
    t_corner c;
    char *final_map;

    if (ac != 2 || openable(av[1]) == 0 || x_max == -1)
        return (84);
    if (y_max == 1) {
        one_column(get_map(av[1]));
        return (0);
    }
    map = put_map_in_tab(get_map(av[1]), x_max, y_max);
    calculated_map = algo_change_tab(map, x_max, y_max);
    c = init_corner(calculated_map, x_max, y_max);
    final_map = put_map_in_str(calculated_map, x_max, y_max, c);
    my_putstr(final_map);
}
