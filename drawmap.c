/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:33:03 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 23:00:37 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/*
** draw_l se inicijalizirat pixels struct, so gi sodrzite krajnite koordinati
** za liniite (spored proekcijata), i se zemat i boja za poc. i kraen tocka
*/

void	draw_horiz_lines(t_tabla *fdf, int x, int y)
{
	t_cpixels pixels;

	if (x + 1 < (int)fdf->gridlen)
	{
		pixels.startx = fdf->finalx[y][x] + fdf->view->xoffset;
		pixels.starty = fdf->finaly[y][x] + fdf->view->offset;
		pixels.endx = fdf->finalx[y][x + 1] + fdf->view->xoffset;
		pixels.endy = fdf->finaly[y][x + 1] + fdf->view->offset;
		pixels.cur_x = pixels.startx;
		pixels.cur_y = pixels.starty;
		pixels.st_color = (fdf->colors[y][x] != -1 ?
			fdf->colors[y][x] : get_default_color(fdf, fdf->grid[y][x]));
		pixels.end_color = (fdf->colors[y][x + 1] != -1 ? fdf->colors[y][x + 1]
								: get_default_color(fdf, fdf->grid[y][x + 1]));
		breshandler(pixels, fdf);
	}
}

void	draw_vert_lines(t_tabla *fdf, int x, int y)
{
	t_cpixels pixels;

	if (y + 1 < (int)fdf->gridht)
	{
		pixels.startx = fdf->finalx[y][x] + fdf->view->xoffset;
		pixels.starty = fdf->finaly[y][x] + fdf->view->offset;
		pixels.endx = fdf->finalx[y + 1][x] + fdf->view->xoffset;
		pixels.endy = fdf->finaly[y + 1][x] + fdf->view->offset;
		pixels.cur_x = pixels.startx;
		pixels.cur_y = pixels.starty;
		pixels.st_color = (fdf->colors[y][x] != -1 ?
			fdf->colors[y][x] : get_default_color(fdf, fdf->grid[y][x]));
		pixels.end_color = (fdf->colors[y + 1][x] != -1 ? fdf->colors[y + 1][x]
								: get_default_color(fdf, fdf->grid[y + 1][x]));
		breshandler(pixels, fdf);
	}
}

/*
** orginal x & y are stored only to get the current color in get_color
*/

void	drawgrid(t_tabla *fdfobj)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	if (fdfobj->view->projection == 'i')
		isoprojection(fdfobj);
	else
		paralelprojection(fdfobj);
	while (y < fdfobj->gridht)
	{
		fdfobj->orgy = y;
		while (x < fdfobj->gridlen)
		{
			fdfobj->orgx = x;
			draw_horiz_lines(fdfobj, x, y);
			draw_vert_lines(fdfobj, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
