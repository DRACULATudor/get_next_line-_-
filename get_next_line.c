/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:18:15 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/27 18:12:07 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_theline(int fd, char *statbuffr, char *buffr)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffr, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(statbuffr);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffr[bytes_read] = '\0';
		if (!statbuffr)
			statbuffr = ft_strdup("");
		temp = statbuffr;
		statbuffr = ft_strjoin(temp, buffr);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffr, '\n'))
			break ;
	}
	return (statbuffr);
}

char	*check_stat(char *line)
{
	int		i;
	char	*statbuffr;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	statbuffr = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!statbuffr)
	{
		free(line);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (statbuffr);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffr;
	static char	*statbuffr;

	buffr = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD || read(fd, 0, 0) < 0)
	{
		free(buffr);
		free(statbuffr);
		buffr = NULL;
		statbuffr = NULL;
		return (NULL);
	}
	if (!buffr)
		return (NULL);
	line = fill_theline(fd, statbuffr, buffr);
	free(buffr);
	if (!line)
	{
		free(statbuffr);
		return (NULL);
	}
	statbuffr = check_stat(line);
	return (line);
}
