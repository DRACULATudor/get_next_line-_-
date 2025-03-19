#include "get_next_line.h" //malloc(ft_calloc) and read functions
#include <stdio.h>

int main(void)
{
    int		fd1;
    char	*line;

    fd1 = open("41_with_nl", O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening file1");
        return (1);
    }

    printf("\nContents of file1:\n\n");
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    if(line == NULL)
    {
        return 0;
        close(fd1);
    }
    return (0);
}
