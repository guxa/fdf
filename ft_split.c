/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:56:34 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 20:30:27 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isdelimiter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

/*
** vo countwords (*x) se prakat za ako stringot pocvit so ' ' ili '\t' i sl.
** da ne vlezat vo prviot word/str praznite mesta, tuku da gi skoknit niv
*/

static size_t	countwords(char *str, int *x)
{
	size_t i;
	size_t words;

	i = 0;
	words = 1;
	while (str[i] && isdelimiter(str[i]))
		i++;
	*x = i;
	while (str[i])
	{
		if (isdelimiter(str[i]))
			words++;
		while (str[i] && isdelimiter(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (words);
}

/*
** line 68 if-ot ako stringot nemat niedno prazno mesto, [x] e veke do kraj
** za da ne go zgolemit i da e nadvor od mem//l62 +1 vo words za da mozit
** da se locirat krajot na char**, za da mozit da se listat
*/

char			**ft_split(char *str)
{
	size_t	words;
	size_t	i;
	int		x;
	int		start;
	char	**strar;

	i = 0;
	x = 0;
	if (str[0] == '\0')
		return (NULL);
	words = countwords(str, &x);
	strar = malloc(sizeof(char*) * words + 1);
	while (i < words)
	{
		start = x;
		while (str[x] && isdelimiter(str[x]) == 0)
			x++;
		if (str[x])
			str[x++] = '\0';
		while (str[x] && isdelimiter(str[x]))
			x++;
		strar[i++] = ft_strdup(&(str[start]));
	}
	strar[i] = NULL;
	return (strar);
}
