/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:45:44 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/21 18:09:32 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// dzabe addtolist e so void*, zs temp morat pak da go imat fiksno
// imeto od struct....

#include "libft.h"

int		**parsefdf(const char *filepath, t_tabla *fdfobj)
{
	int			fd;
	char		*line;
	t_fdflines	*lista;
	t_fdflines	*elem;
	char		*buffer;

	buffer = ft_newstr(BUF_SIZE);
	lista = NULL;
	line = ft_strdup("");
	fd = open (filepath, O_RDONLY, S_IRUSR);
	while (getlinija(fd, &line, buffer))
	{
		elem = malloc(sizeof(t_fdflines*));
		elem->line = line;
		elem->next = NULL;
		addtolist((void**)&lista, elem);
		fdfobj->gridht++;
		line = ft_strdup("");
	}
	close(fd);
	free(buffer);
	return (fdfobj->gridht != 0 ? makeintarr(lista, fdfobj) : NULL);
	// char **test;
	// test = ft_split(lista->line);
	// int i = 0;
	// while (test[i])
	// 	printf("%s\n", test[i++]);
	// while (lista)
	// {
	// 	printf("%s %d\n", lista->line, BUF_SIZE);
	// 	lista = lista->next;
	// }
}

void	addtolist(void **head, void *element)
{
	t_fdflines *tem;

	tem = *head;
	if (element == 0)
		return;
	if (*head == NULL)
	{
		*head = element;
		return ;
	}
	while (tem->next)
		tem = tem->next;
	tem->next = element;
}

int		**makeintarr(t_fdflines *lista, t_tabla *fdfobj)
{
	int i;
	int **tab;
	char **tem;
	int x;

	x = 0;
	if ((tab = malloc(sizeof(int*) * fdfobj->gridht)) == NULL)
		return (NULL);
	while (lista)
	{
		i = 0;
		tem = ft_split(lista->line);
		while (tem[i])
			i++;
		if ((tab[x] = malloc(sizeof(int) * i)) == NULL)
			return (NULL);
		i = -1;
		while (tem[++i])
			tab[x][i] = ft_atoi(tem[i]);
		fdfobj->gridlen = i;
		x++;
		lista = lista->next;
		free(tem);
	}
	return (tab);
}