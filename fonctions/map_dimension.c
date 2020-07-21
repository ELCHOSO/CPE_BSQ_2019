/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** map size
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int get_column(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[10007];
    int rd = read(fd, buffer, 10007);
    int i = 0;
    int line = 1;
    int first_line_char = 0;

    if (rd == -1)
        return (84);
    while (line <= 2) {
        if (line == 1)
            first_line_char++;
        if (buffer[i] == '\n')
            line++;
        i++;
    }
    return (i - first_line_char - 1);
}

int get_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[6];
    int rd = read(fd, buffer, 6);
    int line = 0;
    int i = 0;

    if (rd == -1)
        return (-1);
    while (buffer[i] != '\n') {
        if (buffer[i] < '0' || buffer[i] > '9')
            return (-1);
        line = line * 10 + buffer[i] - 48;
        i++;
    }
    return (line);
}
