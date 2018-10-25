/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:25:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/25 00:38:51 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** breshandler handles the applying of Bresenham alg, according to the
** gradient/slope because the org1 allowed to only draw lines with 
** positive slope(x1 - x0 is longer than y1 - y0) - i.e. top left to down Right
*/

void	breshandler(t_cpixels pix, t_tabla *ta)
{
	int deltay;
	int deltax;

	deltay = FTABS(pix.endy - pix.starty);// fabs from math.h can be used too,
	deltax = FTABS(pix.endx - pix.startx);
	if (deltay < deltax)
	{
		if (pix.startx > pix.endx)
			bresenhaml(swap_pixels(pix), ta);
		else
			bresenhaml(pix, ta);
	}
	else
		{
			if (pix.starty > pix.endy)
				bresenhi(swap_pixels(pix), ta);
			else
				bresenhi(pix, ta);
		}
}

void	bresenhaml(t_cpixels pix, t_tabla *ta)
{
	int dx;
	int dy;
	int diff;
	int yi;

	dx = pix.endx - pix.startx;
	dy = pix.endy - pix.starty;
	diff = 2 * dy - dx;
	if ((yi = 1) && dy < 0)
	{
		dy = -dy;
		yi = -1;
	}
	while (pix.startx <= pix.endx)
	{
		//mlx_pixel_put(ta->mlxptr, ta->winptr, x0, y0, 0xEF8633);
		insert_pixel(ta, pix.startx, pix.starty,
					get_color(ta, pix, pix.startx, pix.starty));
		pix.startx++;
		if (diff > 0)
		{
			pix.starty += yi;
			diff = diff - 2 * dx;
		}
		diff = diff + 2 * dy;
	}
}

void	bresenhi(t_cpixels pix, t_tabla *ta)
{
	int dx;
	int dy;
	int diff;
	int xi;

	dx = pix.endx - pix.startx;
	dy = pix.endy - pix.starty;
	diff = 2 * dy - dx;
	if ((xi = 1) && dx < 0)
	{
		dx = -dx;
		xi = -1;
	}
	while (pix.starty <= pix.endy)
	{
		//mlx_pixel_put(ta->mlxptr, ta->winptr, x0, y0, 0xEF8633);
		insert_pixel(ta, pix.startx, pix.starty,
					get_color(ta, pix, pix.startx, pix.starty));
		pix.starty++;
		if (diff > 0)
		{
			pix.startx += xi;
			diff = diff - 2 * dy;
		}
		diff = diff + 2 * dx;
	}
}

t_cpixels swap_pixels(t_cpixels pix)
{
	int tem;

	tem = pix.startx;
	pix.startx = pix.endx;
	pix.endx = tem;
	tem = pix.starty;
	pix.starty = pix.endy;
	pix.endy = tem;
	return (pix);
}

// void	24okt(23i00)-breshandler(int x0, int y0, int x1, int y1, t_tabla *ta)
// {
// 	int deltay;
// 	int deltax;

// 	deltay = FTABS(y1 - y0); // fabs from math.h can be used too,
// 	deltax = FTABS(x1 - x0);
// 	if (deltay < deltax)
// 	{
// 		if (x0 > x1)
// 			bresenhaml(x1, y1, x0, y0, ta);
// 		else
// 			bresenhaml(x0, y0, x1, y1, ta);
// 	}
// 	else
// 		{
// 			if (y0 > y1)
// 				bresenhi(x1, y1, x0, y0, ta);
// 			else
// 				bresenhi(x0, y0, x1, y1, ta);
// 		}
// }