/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:33:03 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/25 23:10:54 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	getisocord(t_tabla *fdfobj, t_view *view)
{
	int x;
	int y;
	int z;
	int temx;
	int temy;

	x = 0;
	y = 0;
	while (y < (int)fdfobj->gridht)
	{
		while (x < (int)fdfobj->gridlen)
		{
			z = fdfobj->grid[y][x] * view->zoom; //ova za pogolema visina
			temx = x * view->zoom;
			temy = y * view->zoom;
			
			fdfobj->finalx[y][x] = (temx - temy) * cos(0.523599);// * ENLARGE;
			fdfobj->finaly[y][x] = -z + (temx + temy) * sin(0.523599);// * ENLARGE;
			// while (fdfobj->finalx[y][x] + view->xoffset < 30)
			// 	view->xoffset += 10;
			while (fdfobj->finaly[y][x] + view->offset > HEIGHT)
				view->offset -= 30;
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_horiz_lines(t_tabla *fdf, int x , int y, t_view *view)
{
	t_cpixels pixels;

	if (x + 1 < (int)fdf->gridlen)
	{
		pixels.startx = fdf->finalx[y][x] + view->xoffset;
		pixels.starty = fdf->finaly[y][x] + view->offset;
		pixels.endx = fdf->finalx[y][x + 1] + view->xoffset;
		pixels.endy = fdf->finaly[y][x + 1] + view->offset;
		pixels.cur_x = pixels.startx;
		pixels.cur_y = pixels.starty;
		pixels.end_color =  (fdf->colors[y][x + 1] != -1 ? 
			fdf->colors[y][x + 1] : get_default_color(fdf, fdf->grid[y][x + 1]));
		breshandler(pixels, fdf);
	}

}

void	draw_vert_lines(t_tabla *fdf, int x , int y, t_view *view)
{
	t_cpixels pixels;

	//fdf->colortest = 0xEF8633;
	if (y + 1 < (int)fdf->gridht)
	{
		pixels.startx = fdf->finalx[y][x] + view->xoffset;
		pixels.starty = fdf->finaly[y][x] + view->offset;
		pixels.endx = fdf->finalx[y + 1][x] + view->xoffset;
		pixels.endy = fdf->finaly[y + 1][x] + view->offset;
		pixels.cur_x = pixels.startx;
		pixels.cur_y = pixels.starty;
		pixels.end_color =  (fdf->colors[y + 1][x] != -1 ? 
			fdf->colors[y + 1][x] : get_default_color(fdf, fdf->grid[y + 1][x]));
		breshandler(pixels, fdf);
	}

}

void	drawgrid(t_tabla *fdfobj, t_view *view)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	getisocord(fdfobj, view);
	while (y < fdfobj->gridht)
	{
		fdfobj->orgy = y;
		while (x < fdfobj->gridlen)
		{
			fdfobj->orgx = x;
			draw_horiz_lines(fdfobj, x, y, view);
			draw_vert_lines(fdfobj, x , y, view);
			x++;
		}
		x = 0;
		y++;
	}
}
