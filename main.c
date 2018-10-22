/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:50:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/21 16:52:29 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tabinit(t_tabla *table)
{
	table->mlxptr = mlx_init();
	table->winptr = mlx_new_window(table->mlxptr, 500, 500, "test");
	table->mclicked = 0;
	table->grid = NULL;
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
	if ((fdfobj->grid = parsefdf("fdf/maps/42.fdf")) == NULL) 
		return (printf("Nota a valid map\n"));

	//bresenhaml(0, 1, 6, 4, table);
	//bresenhaml(1, 170, 350, 290, table);
	//bresenhaml(3, 2, 15, 5, table);

	//bresenhaml2(1, 17, 11, 29, table);
	mlx_hook(fdfobj->winptr, 4, 0, mouse_press, fdfobj);
	mlx_loop(fdfobj->mlxptr);

	return (0);
}

