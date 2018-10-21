/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:50:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/20 22:25:33 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		parsefdf(const char **filepath)
{

}

int main()
{
	//void	*mlx_ptr;
	//void	*win_ptr;
	t_tabla *table;
	// int i;
	// double z;

	// i = 15;
	// z = 15;
	table = malloc(sizeof(t_tabla));
	table->mlxptr = mlx_init();
	table->winptr = mlx_new_window(table->mlxptr, 500, 500, "test");
	table->mclicked = 0;

	//bresenhaml(0, 1, 6, 4, table);
	//bresenhaml(1, 170, 350, 290, table);
	//bresenhaml(3, 2, 15, 5, table);

	//bresenhaml2(1, 17, 11, 29, table);
	mlx_hook(table->winptr, 4, 0, mouse_press, table);
	mlx_loop(table->mlxptr);

	return (0);
}

// void	tabinit(t_tabla *table)
// {

// }