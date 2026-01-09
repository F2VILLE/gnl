#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = 2;
    char    *line;
    int     i;

    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        printf("Line : %s\n", line);
        line = get_next_line(fd);
    }

    return (0);
}