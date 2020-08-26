/*
** EPITECH PROJECT, 2019
** char_to_int_array
** File description:
** Tranfers a char string to an int string
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/coordinates.h"

int smallest(int min, int b, int c)
{
    min = (b < min) ? b : min;
    min = (c < min) ? c : min;
    return (min);
}

int *char_to_int_array(char *str)
{
    int *array = malloc(sizeof(char) * my_strlen(str));

    for (int a = 0; str[a] != '\n'; a++)
        array[a] = (str[a] == '.') ? 0 : 1;
    return (array);
}

int location_one(int **ar, int nb)
{
    int stop = 0;
    char *str = malloc(sizeof(char) * (nb + 1));

    for (int a = 0; a != nb; a++) {
        if(ar[0][a] == 1 && stop != 0)
            str[a] = '.';
        if (ar[0][a] == 1 && stop == 0) {
            str[a] = 'x';
            stop = 1;
        }
        if (ar[0][a] == 0)
            str[a] = 'o';
    }
    my_putstr(str);
    return (stop);
}

char map(struct square big, int value, int a, int b)
{
    char c;

    if ((big.x >= a && a >= big.x - (big.biggest - 1)) &&
        (big.y >= b && b >= big.y - (big.biggest - 1)))
        c = 'x';
    else
        c = '.';
    if (value == 0)
        c = 'o';
    return (c);
}

int final_char_array(int **arr, struct square big, struct map data)
{
    char *f_buffer[data.mapy + 1];
    int a = 0;
    int b = 0;

    for (a = 0; a != data.mapy + 1; a++)
        f_buffer[a] = malloc(sizeof(char) * (data.mapx + 1));
    for (a = 0; a != data.mapy; a++) {
        for (b = 0; b != data.mapx; b++)
            f_buffer[a][b] = map(big, arr[a][b], a, b);
       f_buffer[a][b + 1] = '\n';
    }
    for (a = 0; a != data.mapy; a++)
      my_putstr(f_buffer[a]);
    return (0);
}
