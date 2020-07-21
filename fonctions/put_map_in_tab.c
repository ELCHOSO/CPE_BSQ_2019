/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** mets la map dans un tab
*/

#include "my.h"
#include <sys/stat.h>

char *get_map(char const *filepath)
{
    int size;
    struct stat st;
    int x = get_column(filepath);
    int y = get_line(filepath);
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    int rd;
    int i = 0;

    if (stat(filepath, &st) != 0)
        return ("ERROR");
    size = st.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    rd = read(fd, buffer, size);
    while (buffer[i] != '\n')
        i++;
    i++;
    buffer[size] = '\0';
    return (buffer + i);
}

int **put_map_in_tab(char *str, int last_line, int last_column)
{
    int **tab = malloc(sizeof(int) * last_line * last_column);
    int i = 0;
    int column = 0;

    for (int line = 0; line != last_line; line++)
        tab[line] = malloc(sizeof(int) * last_column);
    for (int line = 0; line != last_line; line++) {
        for (; column != last_column; column++, i++) {
            if (str[i] == '\n')
                i++;
            if (str[i] == 'o')
                tab[line][column] = 0;
            if (str[i] == '.')
                tab[line][column] = 1;
        }
        column = 0;
    }
    tab[last_line] = 0;
    return (tab);
}
