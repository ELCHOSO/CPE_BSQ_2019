/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** gestion d'erreur
*/

#include "my.h"
#include <sys/stat.h>

int openable(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[1];
    int rd = read(fd, buffer, 1);

    if (rd == -1)
        return (0);
    return (1);
}

int is_map_ok(char *map)
{
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] != '.' || map[i] != 'o' || map[i] != '\n')
            return (0);
    }
    return (1);
}
