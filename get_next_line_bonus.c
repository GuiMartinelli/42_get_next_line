/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:05:06 by guferrei          #+#    #+#             */
/*   Updated: 2021/07/04 23:18:44 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

char	*line_cpy(char *src)
{
	int		size;
	int		c;
	char	*dest;

	size = 0;
	c = 0;
	while (*(src + size))
	{
		if (*(src + size) == '\n')
			break ;
		size++;
	}
	dest = malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (c < size)
	{
		*(dest + c) = *(src + c);
		c++;
	}
	*(dest + c) = '\0';
	return (dest);
}

char	*newline_cpy(char **stt)
{
	char	*new_stt;
	char	*aux;

	aux = *stt;
	while (*aux && *aux != '\n')
		aux++;
	if (*aux == '\n')
		aux++;
	new_stt = malloc((gnl_strlen(aux) + 1) * sizeof(char));
	if (!new_stt)
		return (NULL);
	gnl_strcpy(aux, new_stt);
	free(*stt);
	return (new_stt);
}

int	free_and_return(char **pt1, char **pt2, int i)
{
	if (i == -1)
	{
		free (*pt1);
		free (*pt2);
		*pt2 = NULL;
		return (-1);
	}
	else
	{
		free (*pt2);
		*pt2 = NULL;
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*stt[OPEN_MAX];
	char		*buffer;
	int			size;

	buffer = safety_first(fd, line);
	if (!buffer)
		return (-1);
	size = 1;
	while (size > 0 && gnl_strchr(stt[fd]) > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (free_and_return(&buffer, &stt[fd], -1));
		*(buffer + size) = '\0';
		stt[fd] = gnl_strjoin(buffer, &stt[fd]);
	}
	free (buffer);
	*line = line_cpy(stt[fd]);
	stt[fd] = newline_cpy(&stt[fd]);
	if (size == 0)
		return (free_and_return(&buffer, &stt[fd], 0));
	else
		return (1);
}
