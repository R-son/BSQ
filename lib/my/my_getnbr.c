/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Returns a number, sent to the function as a string
*/

#include <unistd.h>

void my_put_error(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++)
        write(2, &str[a], 1);
}

int my_getnbr(char const *str)
{
    int number = 0;
    int a = 0;

    for (; str[a] != '\0'; a++)
        for (; '0' <= str[a] && str[a] <= '9' ; a++) {
            number *= 10;
            number += str[a] - '0';
        }
    return (number);
}

int check_1st_line(char const *str)
{
    if ('0' <= str[0] && str[0] <= '9')
        return (0);
    my_put_error("First character isn't a number\n");
    return (84);
}
