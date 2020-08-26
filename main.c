/*
** EPITECH PROJECT, 2019
** main
** File description:
** BSQ's main
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/coordinates.h"

int location(int **array, int nb, int nb2)
{
    int a = 0;
    int b = 0;
    struct square big;
    struct map data;

    big.biggest = 0;
    big.x = 0;
    big.y = 0;
    for (a = 0; a != nb2; a++)
        for (b = 0; b != nb; b++)
            if (array[a][b] > big.biggest) {
                big.biggest = array[a][b];
                big.x = a;
                big.y = b;
            }
    data.mapx = nb;
    data.mapy = nb2;
    final_char_array(array, big, data);
}

int invalid_char(char *buffer)
{
    for (int a = 0; buffer[a] != '\0'; a++) {
        if (buffer[a] < '0' || buffer[a] > '9')
            switch (buffer[a])
            {
            case '.':
            case 'o':
            case '\n':
                break;
            default :
                my_put_error("Invalid character found\n");
                return (84);
            }
    }
    return (0);
}

int final_array(int **ar, int nb, int nb2)
{
    int a = 0;
    int b = 0;
    int s = 0;

    if (nb2 == 1) {
        location_one(ar, nb);
        return (0);
    }
    for (a = 1; a != nb2; a++) {
        for (b = 1; b != nb; b++) {
            if (ar[a][b] != 0) {
                s = smallest(ar[a - 1][b], ar[a][b - 1], ar[a - 1][b - 1]);
                ar[a][b] += s;
            }
        }
    }
    location(ar, nb, nb2);
    return (0);
}

int buffer_to_char_array(char *buffer, int size, int n)
{
    int a = 0;
    int c = 0;
    int b = size / my_getnbr(buffer);
    int *array[my_getnbr(buffer)];
    struct coordinates len;

    if (invalid_char(buffer) == 84)
        return (84);
    for (int d = 0; d != my_getnbr(buffer); d++)
        array[d] = malloc(sizeof(int) * b);
    for (a = 0; buffer[a] != '.' && buffer[a] != 'o'; a++)
        if (buffer[a] == '\0') {
            my_put_error("Valid characters not found\n");
            return (84);
        }
    for (b = 0; b != my_getnbr(buffer); b++, a++)
        for (c = 0; buffer[a] != '\n' && buffer[a] != '\0'; a++, c++)
            array[b][c] = (buffer[a] == '.') ? 1 : 0;
    final_array(array, c, b);
    return (0);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    int test_read = 0;
    char *buffer;
    int size = 0;
    struct stat st;

    stat(av[1], &st);
    size = st.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    test_read = read(fd, buffer, size);
    if (ac < 2 || ac > 2)
        return (n_arg());
    if (test_read == -1) {
        my_put_error("Couldn't manage to open the file\n");
        return (84);
    }
    if (check_1st_line(buffer) == 84)
        return (84);
    buffer_to_char_array(buffer, size, 1);
    return (0);
}
