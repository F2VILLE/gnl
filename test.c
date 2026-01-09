#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    printf("Argc : %d\n", argc);
    if (argc != 2)
    {
        printf("Usage: %s <file>", argv[0]);
        return (0);
    }
    int fd = open(argv[1], O_RDONLY);
    printf("Fd: %d\n", fd);
    if (fd < 0)
    {
        printf("Error opening file");
        return (1);
    }
    char    *line;
    int     i;

    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        printf("Line : %s\n", line);
        free(line);
        line = get_next_line(fd);
    }

    return (0);
}
