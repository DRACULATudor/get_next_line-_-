/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:18:15 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/19 21:10:57 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(int fd, char *arr)
{
	int		i;
	int		bytes_read;
	char	*str;
	int		j;

	str = malloc(100000);
	ft_memset(str, '\0', 100000);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		i = 0;
		while (i < BUFFER_SIZE && arr[i] == '\0')
			i++;
		if (i == BUFFER_SIZE)
			bytes_read = read(fd, arr, BUFFER_SIZE); // pas 1 trb modificari
		j = 0;
		while (arr[j] != '\n' && j < BUFFER_SIZE)
		{
			str[j] = arr[j]; //i trb setat	 // pas 2
			i++;
		}
		ft_memset(arr, '\0', i + 1); //pas 3
		if(j == BUFFER_SIZE)
			{
				//cplm sa facccccccccc
			}
		if(str[j] == '\n')
			{
				str[j] = '\0';
				return(str);
			}
		else
			bytes_read = read(fd, arr, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(arr);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	arr[1021][BUFFER_SIZE];
	char		*str;
	int			i;

	i = 0;
	if (fd >= 3 && fd < 1024)
	{
	}
}

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;
//     char arr[BUFFER_SIZE + 1];
//     char *buff = NULL;

//     if (argc != 2)
//     {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return (1);
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     while ((line = get_line(fd, arr, buff)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }