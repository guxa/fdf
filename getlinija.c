/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlinija.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:10:19 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/17 22:21:25 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getlinija(int filedesc, t_triler *filer)
{
	char	*nl;

	if (checkresto(filer))
		return (1);
	while ((filer->bred = read(filedesc, filer->buffer, BUF_SIZE)) > 0)
	{
		filer->buffer[filer->bred] = '\0';
		if ((nl = ft_strchr(filer->buffer, '\n')))
		{
			filer->temp = filer->line;
			*nl = '\0';
			filer->line = ft_joinstr(filer->line, filer->buffer);
			filer->rest = ft_strdup(++nl);
			free(filer->temp);
			return (1);
		}
		else
		{
			filer->temp = filer->line;
			filer->line = ft_joinstr(filer->line, filer->buffer);
			free(filer->temp);
		}
	}
	return (0);
}

int		checkresto(t_triler *filer)
{
	char *nl;

	if (!filer->rest || filer->rest[0] == '\0')
	{
		free(filer->rest);
		return (0);
	}
	if ((nl = ft_strchr(filer->rest, '\n')))
	{
		*nl = '\0';
		filer->temp = filer->line;
		filer->line = ft_joinstr(filer->line, filer->rest);
		free(filer->temp);
		filer->temp = filer->rest;
		filer->rest = ft_strdup(++nl);
		free(filer->temp);
		return (1);
	}
	free(filer->line);
	filer->line = ft_strdup(filer->rest);
	free(filer->rest);
	return (0);
}
