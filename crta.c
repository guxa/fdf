/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:25:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 23:00:30 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/*
** breshandler handles the applying of Bresenham alg, according to the
** gradient/slope because the org1 allowed to only draw lines with
** positive slope(x1 - x0 is longer than y1 - y0) - i.e. top left to down Right
*/

void		breshandler(t_cpixels pix, t_tabla *fdf)
{
	int deltay;
	int deltax;

	deltay = FTABS(pix.endy - pix.starty);
	deltax = FTABS(pix.endx - pix.startx);
	if (deltay < deltax)
	{
		if (pix.startx > pix.endx)
			bresenhaml(swap_pixels(pix), fdf);
		else
			bresenhaml(pix, fdf);
	}
	else
	{
		if (pix.starty > pix.endy)
			bresenhi(swap_pixels(pix), fdf);
		else
			bresenhi(pix, fdf);
	}
}

/*
** use mlx_pixel_put to draw on board
*/

void		bresenhaml(t_cpixels pix, t_tabla *fdf)
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
	while (pix.cur_x <= pix.endx)
	{
		insert_pixel(fdf, pix.cur_x, pix.cur_y,
					get_color(pix, pix.cur_x, pix.cur_y));
		pix.cur_x++;
		if (diff > 0)
		{
			pix.cur_y += yi;
			diff = diff - 2 * dx;
		}
		diff = diff + 2 * dy;
	}
}

void		bresenhi(t_cpixels pix, t_tabla *fdf)
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
	while (pix.cur_y <= pix.endy)
	{
		insert_pixel(fdf, pix.cur_x, pix.cur_y,
					get_color(pix, pix.cur_x, pix.cur_y));
		pix.cur_y++;
		if (diff > 0)
		{
			pix.cur_x += xi;
			diff = diff - 2 * dy;
		}
		diff = diff + 2 * dx;
	}
}

/*
** A complete solution would need to detect whether x1 > x0 or y1 > y0 and
** reverse the input coordinates before drawing, thus (wiki ish :)
*/

t_cpixels	swap_pixels(t_cpixels pix)
{
	int tem;

	tem = pix.startx;
	pix.startx = pix.endx;
	pix.endx = tem;
	tem = pix.starty;
	pix.starty = pix.endy;
	pix.endy = tem;
	pix.cur_x = pix.startx;
	pix.cur_y = pix.starty;
	tem = pix.st_color;
	pix.st_color = pix.end_color;
	pix.end_color = tem;
	return (pix);
}
