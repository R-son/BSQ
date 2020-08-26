/*
** EPITECH PROJECT, 2019
** coordinates
** File description:
** Contains coordinates for the square
*/

#ifndef COORD_H_
#define COORD_H_

struct coordinates
{
    int line_len;
    int size;
    int line;
    int column;
};

struct square
{
    int x;
    int y;
    int biggest;
};

struct map
{
    int mapx;
    int mapy;
};

int main(int ac, char **av);
int final_char_array(int **arr, struct square big, struct map data);
int location_one(int **array, int nb);

#endif /*COORD_H_*/
