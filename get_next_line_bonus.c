/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:07:49 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/29 14:53:36 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_theline(int fd, char *statbuffer, char *buff)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(statbuffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!statbuffer)
			statbuffer = ft_strdup("");
		temp = statbuffer;
		statbuffer = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (statbuffer);
}

char	*update_stat(char *line)
{
	int		i;
	char	*statbuffer;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	statbuffer = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!statbuffer)
	{
		free(statbuffer);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (statbuffer);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*statbuffer[MAX_FD];

	buff = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| fd == 1 || fd == 2)
	{
		free(buff);
		free(statbuffer[fd]);
		buff = NULL;
		statbuffer[fd] = NULL;
		return (NULL);
	}
	if (!buff)
		return (NULL);
	line = fill_theline(fd, statbuffer[fd], buff);
	free(buff);
	if (!line)
		return (NULL);
	statbuffer[fd] = update_stat(line);
	return (line);
}
