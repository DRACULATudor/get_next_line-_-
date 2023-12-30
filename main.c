/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:28:34 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/29 13:54:07 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" //malloc(ft_calloc) and read functions

#include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	int 	fd2;
// 	char	*text;
// 	char	*text2;

// 	// fd = 3;
// 	// while (fd == 0)
// 	// {
// 	// 	/* code */
// 	// }
	
	
// 	fd = open("41_with_nl", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	fd2 = open("42_nl", O_RDONLY);
// 	if (fd2 == -1)
// 	{
// 		perror("Error opening file");
// 		close(fd);
// 		return (1);
// 	}
// 	int flag1;
// 	int flag2;

// 	flag1 = 1;
// 	flag2 = 1;
// 	while (flag1 != 0 || flag2 != 0)
// 	{
// 		if(flag1 == 1)
// 		{
// 			text = get_next_line(fd);
// 			if (!text)
// 			{
// 				return(0);
// 			}
// 			flag1 = 0;
// 			printf("%s\n", text);
// 			free(text);
// 		}
// 		if(flag2 == 1)
// 		{
// 			text2 = get_next_line(fd2);
// 			if (!text2)
// 			{
// 				return(0);
// 			}
// 			flag2 = 0;
// 			printf("%s\n", text2);
// 			free(text2);
// 		}
// 		flag1 = 1;
// 		flag2 = 1;
// 	}
// 	close(fd);
// 	close(fd2);
// 	return (0);
// }
int main(void)
{
    int		fd1, fd2;
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
    close(fd1);

    fd2 = open("42_nl", O_RDONLY);
    if (fd2 == -1)
    {
        perror("Error opening file2");
        return (1);
    }

    printf("\n\nContents of file2:\n\n");
    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd2);

    return (0);
}
