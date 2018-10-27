/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:50:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/26 18:47:29 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tabinit(t_tabla *table)
{
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
	table->data_add = mlx_get_data_addr(table->img, &(table->bpp), &(table->size_line)
		, &(table->endian));
	table->colors = NULL;
	table->orgx = 0;
	table->orgy = 0;
	table->view = NULL;
}

int		initxyarr(t_tabla *fdfobj)
{
	size_t i;

	i = 0;
	if ((fdfobj->finalx = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		return (b_printf("Malloc failed"));
	if ((fdfobj->finaly = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		return (b_printf("Malloc failed"));
	while (i < fdfobj->gridht)
	{
		if ((fdfobj->finalx[i] = malloc(sizeof(int) * fdfobj->gridlen)) == NULL)
			return (b_printf("Malloc failed"));
		if ((fdfobj->finaly[i] = malloc(sizeof(int) * fdfobj->gridlen)) == NULL)
			return (b_printf("Malloc failed"));
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_tabla *fdfobj;
	if (argc < 2)
		return (printf("no params\n"));
	
	fdfobj = malloc(sizeof(t_tabla));
	tabinit(fdfobj);
	if (parsefdf(argv[1], fdfobj) == -1)
		return (printf("Not a valid map\n"));
	if (initxyarr(fdfobj) != 0)
		return (-1);
	
	fdfobj->view = init_view(fdfobj->gridlen, fdfobj->gridht, fdfobj->maxz);

	generateimg(fdfobj);
	mlx_hook(fdfobj->winptr, 4, 0, mouse_press, fdfobj);
	mlx_hook(fdfobj->winptr, 6, 0, mouse_move, fdfobj);
	mlx_hook(fdfobj->winptr, 5, 0, mouse_release, fdfobj);
	mlx_hook(fdfobj->winptr, 2, 0, key_press, fdfobj);
	mlx_hook(fdfobj->winptr, 17, 0, close_app, fdfobj);
	mlx_loop(fdfobj->mlxptr);

	return (0);
}

