/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:13:22 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 23:03:56 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_tabla		*tabinit(void)
{
	t_tabla *table;

	if ((table = malloc(sizeof(t_tabla))) == NULL)
		exit_app("Malloc inside tabinit()");
	table->mlxptr = mlx_init();
	table->winptr = mlx_new_window(table->mlxptr, WIDTH, HEIGHT, "FdF j.g.");
	table->mclicked = 0;
	table->grid = NULL;
	table->gridlen = 0;
	table->gridht = 0;
	table->finalx = NULL;
	table->finaly = NULL;
	table->maxz = 0;
	table->img = mlx_new_image(table->mlxptr, WIDTH, HEIGHT);
	table->data_add = mlx_get_data_addr(table->img, &(table->bpp),
							&(table->size_line), &(table->endian));
	table->colors = NULL;
	table->orgx = 0;
	table->orgy = 0;
	table->view = NULL;
	return (table);
}

void		initxyarr(t_tabla *fdfobj)
{
	size_t i;

	i = 0;
	if ((fdfobj->finalx = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		exit_app("Malloc inside initxyarr() failed");
	if ((fdfobj->finaly = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		exit_app("Malloc inside initxyarr() failed");
	while (i < fdfobj->gridht)
	{
		if ((fdfobj->finalx[i] = malloc(sizeof(int) * fdfobj->gridlen)) == NULL)
			exit_app("Malloc inside initxyarr() failed");
		if ((fdfobj->finaly[i] = malloc(sizeof(int) * fdfobj->gridlen)) == NULL)
			exit_app("Malloc inside initxyarr() failed");
		i++;
	}
}

void		exit_app(const char *source)
{
	b_printf("%s\n", source);
	exit(1);
}

void		clear_list(t_fdflines **head, char *laststr)
{
	t_fdflines *tem;

	free(laststr);
	while (*head)
	{
		tem = *head;
		*head = (*head)->next;
		free(tem->line);
		free(tem);
	}
	*head = NULL;
}
