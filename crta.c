/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:25:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/21 16:04:55 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// testirano bre i bre2, isto izgledet liniite

#include "libft.h"

void	breshandler(int x0, int y0, int x1, int y1, t_tabla *ta)
{
	int resy;
	int resx;

	if ((resy = y1 - y0) < 0)
		resy = -resy;
	if ((resx = x1 - x0) < 0)
		resx = -resx;
	if (resy < resx)
	{
		if (x0 > x1)
			bresenhaml(x1, y1, x0, y0, ta);
		else
			bresenhaml(x0, y0, x1, y1, ta);
	}
	else
		{
			if (y0 > y1)
				bresenhi(x1, y1, x0, y0, ta);
			else
				bresenhi(x0, y0, x1, y1, ta);
		}
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
	if ((yi = 1) && dy < 0)
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
			y0 += yi;
			diff = diff - 2 * dx;
		}
		diff = diff + 2 * dy;
	}
}

void	bresenhi(int x0, int y0, int x1, int y1, t_tabla *ta)
{
	int dx;
	int dy;
	int diff;
	int xi;

	dx = x1 - x0;
	dy = y1 - y0;
	diff = 2 * dy - dx;
	if ((xi = 1) && dx < 0)
	{
		dx = -dx;
		xi = -1;
	}
	while (y0 <= y1)
	{
		mlx_pixel_put(ta->mlxptr, ta->winptr, x0, y0, 0xFFFFFF);
		//printf("%d %d\n", x0, y0);
		y0++;
		if (diff > 0)
		{
			x0 += xi;
			diff = diff - 2 * dy;
		}
		diff = diff + 2 * dx;
	}
}

// D = 2 * dy - (dx - 1) - (2 * dy - dx);
// D = 2 * dy - dx + 1 - 2 * dy + dx == +1

//// D = 2 * (dy - 1) - dx + 1 -2dy +dx == -2 -dx + 1 +dx = -1
// void	bresenhaml2(int x0, int y0, int x1, int y1, t_tabla *ta)
// {
// 	int dx;
// 	int dy;
// 	int diff;

// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	diff = 2 * dy - dx;
// 	while (x0 <= x1)
// 	{
// 		mlx_pixel_put(ta->mlxptr, ta->winptr, x0, y0, 0xFFFFFF);
// 		//printf("%d %d\n", x0, y0);
// 		x0++;
// 		if (diff < 0)
// 			diff = diff + 2 * dy;
// 		else
// 		{
// 			y0++;
// 			diff = diff + 2 * (dy - dx);
// 		}
// 	}
// }