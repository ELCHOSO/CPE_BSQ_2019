/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** my.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int get_line(char const *filepath);
int get_column(char const *filepath);
int **put_map_in_tab(char *str, int, int);
char *get_map(char const *filepath);
int min(int, int, int);
int **algo_change_tab(int **, int, int);
int find_corner_x(int **, int, int);
int find_corner_y(int **, int, int);
int find_sqr_size(int **, int, int);
int is_sqr(int x, int beginning, int end);
int openable(char const *);

struct corner
{
    int x;
    int y;
    int size;
    int x_beg;
    int y_beg;
};

typedef struct corner t_corner;
t_corner init_corner(int **, int, int);
