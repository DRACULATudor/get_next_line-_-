/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:28:34 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/27 17:58:57 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" //malloc(ft_calloc) and read functions

int	main(void)
{
	int		fd;
	char	*text;

	fd = open("41_with_nl", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (1)
	{
		text = get_next_line(fd);
		if (text == NULL)
			break ;
		printf("%s", text);
		free(text);
	}
	return (0);
}
