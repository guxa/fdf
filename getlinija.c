/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlinija.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:10:19 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 18:52:19 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getlinija(int filedesc, char **line, char *buffer)
{
	char		*nl;
	int			bred;
	char		*temp;
	static char *rest;

	if (checkresto(line, &rest))
		return (1);
	while ((bred = read(filedesc, buffer, BUF_SIZE)) > 0)
	{
		buffer[bred] = '\0';
		if ((nl = ft_strchr(buffer, '\n')))
		{
			temp = *line;
			*nl = '\0';
			*line = ft_joinstr(*line, buffer);
			rest = ft_strdup(++nl);
			free(temp);
			return (1);
		}
		temp = *line;
		*line = ft_joinstr(*line, buffer);
		free(temp);
	}
	rest = 0;
	return (ft_strlen(*line) > 0 ? 1 : 0);
	// ovde bese samo return (0); bez rest = 0, i drugava logika
}

int		checkresto(char **line, char **rest)
{
	char *nl;
	char *temp;

	if (!*rest || *rest[0] == '\0')
	{
		free(*rest);
		return (0);
	}
	if ((nl = ft_strchr(*rest, '\n')))
	{
		*nl = '\0';
		temp = *line;
		*line = ft_joinstr(*line, *rest);
		free(temp);
		temp = *rest;
		*rest = ft_strdup(++nl);
		free(temp);
		return (1);
	}
	free(*line);
	*line = ft_strdup(*rest);
	free(*rest);
	return (0);
}
