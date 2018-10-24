/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:50:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/23 17:08:47 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tabinit(t_tabla *table)
{
	table->mlxptr = mlx_init();
	table->winptr = mlx_new_window(table->mlxptr, WIDTH, HEIGHT, "Proba");
	table->mclicked = 0;
	table->grid = NULL;
	table->gridlen = 0;
	table->gridht = 0;
	table->posx = NULL;
	table->posy = NULL;
	table->offset = 0;
	table->test = 0;
	table->img = mlx_new_image(table->mlxptr, WIDTH, HEIGHT);
	table->data_add = mlx_get_data_addr(table->img, &(table->bpp), &(table->size_line)
		, &(table->endian));
	table->colortest = 0xFFFFFF;
}

int		initxyarr(t_tabla *fdfobj)
{
	size_t i;

	i = 0;
	if ((fdfobj->posx = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		return (printf("Malloc failed"));
	if ((fdfobj->posy = malloc(sizeof(int *) * fdfobj->gridht)) == NULL)
		return (printf("Malloc failed"));
	while (i < fdfobj->gridht)
	{
		if ((fdfobj->posx[i] = malloc(sizeof(int) * fdfobj->gridlen)) == NULL)
			return (printf("Malloc failed"));
		if ((fdfobj->posy[i] = malloc(sizeof(int) * fdfobj->gridlen)) == NULL)
			return (printf("Malloc failed"));
		i++;
	}
	return (0);
}

int main()
{
	// int i;
	// double z;
	t_tabla *fdfobj;

	// i = 15;
	// z = 15;
	fdfobj = malloc(sizeof(t_tabla));
	tabinit(fdfobj);
	if ((fdfobj->grid = parsefdf("fdf/maps/42.fdf", fdfobj)) == NULL) 
		return (printf("Nota a valid map\n"));
	if (initxyarr(fdfobj) != 0)
		return (-1);
	//bresenhaml(0, 1, 6, 4, table);
	//bresenhaml(1, 170, 350, 290, table);
	//bresenhaml(3, 2, 15, 5, table);
	//bresenhaml2(1, 17, 11, 29, table);
		//breshandler(0, 0, 15, 9, fdfobj);
	drawgrid(fdfobj);
	//generateimg(fdfobj);
	mlx_hook(fdfobj->winptr, 4, 0, mouse_press, fdfobj);
	mlx_loop(fdfobj->mlxptr);

	return (0);
}

