/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:25:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/20 19:30:28 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// testirano bre i bre2, isto izgledet liniite

#include "libft.h"

void	breshandler(int x0, int y0, int x1, int y1, t_tabla *ta)
{
	if ((y1 - y0) < (x1 - x0))
	{
		if (x0 > x1)
			bresenhaml(x1, y1, x0, y0, ta);
		else
			bresenhaml(x0, y0, x1, y1, ta);
	}
	// else
	// 	{
	// 		if (y0 > y1)
	// 			negbres(x1, y1, x0, y0);
	// 		else
	// 			negbres(x0, y0, x1, y1);
	// 	}
}

void	bresenhaml(int x0, int y0, int x1, int y1, t_tabla *ta)
{
	int dx;
	int dy;
	int diff;
	int yi;

	dx = x1 - x0;
	dy = y1 - y0;
	diff = 2 * dy - dx;
	if ((yi = 1) & dy < 0)
	{
		dy = -dy;
		yi = -1;
	}
	while (x0 <= x1)
	{
		mlx_pixel_put(ta->mlxptr, ta->winptr, x0, y0, 0xFFFFFF);
		//printf("%d %d\n", x0, y0);
		x0++;
		if (diff > 0)
		{
			y0++;
			diff = diff - 2 * dx;
		}
		diff = diff + 2 * dy;
	}
}

// D = 2 * dy - (dx - 1) - (2 * dy - dx);
// D = 2 * dy - dx + 1 - 2 * dy + dx == +1

//// D = 2 * (dy - 1) - dx + 1 -2dy +dx == -2 -dx + 1 +dx = -1
void	bresenhaml2(int x0, int y0, int x1, int y1, t_tabla *ta)
{
	int dx;
	int dy;
	int diff;

	dx = x1 - x0;
	dy = y1 - y0;
	diff = 2 * dy - dx;
	while (x0 <= x1)
	{
		mlx_pixel_put(ta->mlxptr, ta->winptr, x0, y0, 0xFFFFFF);
		//printf("%d %d\n", x0, y0);
		x0++;
		if (diff < 0)
			diff = diff + 2 * dy;
		else
		{
			y0++;
			diff = diff + 2 * (dy - dx);
		}
	}
}