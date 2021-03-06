/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 00:45:44 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/28 01:54:32 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	addtolist(t_fdflines **head, t_fdflines *element)
{
	t_fdflines *tem;

	tem = *head;
	if (element == 0)
		return ;
	if (*head == NULL)
	{
		*head = element;
		return ;
	}
	while (tem->next)
		tem = tem->next;
	tem->next = element;
}

void		parsefdf(const char *filepath, t_tabla *fdfobj)
{
	int			fd;
	char		*line;
	t_fdflines	*lista;
	t_fdflines	*elem;
	char		*buffer;

	buffer = ft_newstr(BUF_SIZE);
	lista = NULL;
	line = ft_strdup("");
	fd = open(filepath, O_RDONLY, S_IRUSR);
	while (getlinija(fd, &line, buffer))
	{
		elem = malloc(sizeof(t_fdflines*));
		elem->line = line;
		elem->next = NULL;
		addtolist(&lista, elem);
		fdfobj->gridht++;
		line = ft_strdup("");
	}
	close(fd);
	free(buffer);
	if (fdfobj->gridht == 0)
		exit_app("Invalid map");
	makeintarr(lista, fdfobj);
	clear_list(&lista, line);
}

static void	free_strarr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/*
** store_alt_color, gets the altitude Z and color (if specified) for each
** point of the map, if there is no color for that point, -1 is inserted
** check in while loop not to parse empty "" or invalid str
** go baram samo max Z, potrebna za get color, a ko min Z se koristit 0
*/

static void	store_alt_color(char **strarr, t_tabla *fdf, int x, int length)
{
	int		i;
	char	*tem;

	i = 0;
	tem = NULL;
	if ((fdf->colors[x] = malloc(sizeof(int) * length)) == NULL)
		exit_app("Malloc in store_alt_color() failed");
	while (strarr[i] && (ft_isdigit(strarr[i][0]) || strarr[i][0] == '-'))
	{
		fdf->colors[x][i] = -1;
		if ((tem = ft_strchr(strarr[i], ',')))
		{
			tem += 3;
			fdf->colors[x][i] = myatoi_base(tem, 16);
		}
		fdf->grid[x][i] = ft_atoi(strarr[i]);
		if (fdf->grid[x][i] > fdf->maxz)
			fdf->maxz = fdf->grid[x][i];
		i++;
	}
	if (fdf->gridlen != 0 && i != (int)fdf->gridlen)
		exit_app("Invalid map file (map line length)");
	fdf->gridlen = i;
}

/*
** Creates 2 arrays of int arrays from the map lines inside the list
*/

void		makeintarr(t_fdflines *lista, t_tabla *fdfobj)
{
	int		i;
	char	**tem;
	int		x;

	x = 0;
	if ((fdfobj->grid = malloc(sizeof(int*) * fdfobj->gridht)) == NULL)
		exit_app("Malloc inside makeintarr() failed");
	if ((fdfobj->colors = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		exit_app("Malloc inside makeintarr() failed");
	while (lista)
	{
		i = 0;
		tem = ft_split(lista->line);
		while (tem[i])
			i++;
		if ((fdfobj->grid[x] = malloc(sizeof(int) * i)) == NULL)
			exit_app("Malloc inside makeintarr() failed");
		store_alt_color(tem, fdfobj, x, i);
		x++;
		lista = lista->next;
		free_strarr(tem);
	}
}
