/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:45:44 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/23 21:23:24 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// dzabe addtolist e so void*, zs temp morat pak da go imat fiksno
// imeto od struct....

#include "libft.h"

int		parsefdf(const char *filepath, t_tabla *fdfobj)
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
	return (fdfobj->gridht != 0 ? makeintarr(lista, fdfobj) : -1);
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

static void	free_strarr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free (arr);
}

static int	store_alt_color(char **strarr, t_tabla *fdfobj, int x, int length)
{
	int i;
	char *tem;

	i = 0;
	tem = NULL;
	if ((fdfobj->colors[x] = malloc(sizeof(int) * length)) == NULL)
		return (-1);
	while (strarr[i])
	{
		fdfobj->colors[x][i] = -1;
		if ((tem = ft_strchr(strarr[i], ',')))
		{
			tem += 3;
			fdfobj->colors[x][i] = myatoi_base(tem, 16);
		}
		fdfobj->grid[x][i] = ft_atoi(strarr[i]);
		i++;
	}
	fdfobj->gridlen = i; // mozit da se stavit proverka za dali e isto so prethodnite
	return (0);
}

int		makeintarr(t_fdflines *lista, t_tabla *fdfobj)
{
	int i;
	char **tem;
	int x;

	x = 0;
	if ((fdfobj->grid = malloc(sizeof(int*) * fdfobj->gridht)) == NULL)
		return (-1);
	if ((fdfobj->colors = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		return (-1);
	while (lista)
	{
		i = 0;
		tem = ft_split(lista->line);
		while (tem[i])
			i++;
		if ((fdfobj->grid[x] = malloc(sizeof(int) * i)) == NULL)
			return (-1);
		if (store_alt_color(tem, fdfobj, x, i))
			return (-1);
		x++;
		lista = lista->next;
		free_strarr(tem);
	}
	return (1);
}
