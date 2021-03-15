/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAUL <RAUL@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:44:43 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/03/15 13:46:31 by RAUL             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_aux(char **aux, char **line, ssize_t reader)
{
	char	*str;

	if (!*aux && reader == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((str = ft_strchr(*aux, '\n')))
	{
		*(str)++ = '\0';
		str = ft_strdup(str);
		*line = ft_strdup(*aux);
		free(*aux);
		*aux = NULL;
		*aux = str;
		return (1);
	}
	*line = *aux;
	*aux = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*join;
	ssize_t		reader;
	static char	*aux[4096];
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((reader = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reader] = '\0';
		if (!aux[fd])
			aux[fd] = ft_strdup(buffer);
		else
		{
			join = ft_strjoin(aux[fd], buffer);
			free(aux[fd]);
			aux[fd] = NULL;
			aux[fd] = join;
		}
		if (ft_strchr(aux[fd], '\n'))
			break ;
	}
	if (reader < 0)
		return (-1);
	return (ft_aux(&aux[fd], line, reader));
}
