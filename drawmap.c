/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:33:03 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/25 01:15:38 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	getisocord(t_tabla *fdfobj)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	while (y < (int)fdfobj->gridht)
	{
		while (x < (int)fdfobj->gridlen)
		{
			z = fdfobj->grid[y][x] * ENLARGE; //ova za pogolema visina
			fdfobj->finalx[y][x] = (x - y) * cos(0.523599) * ENLARGE;
			fdfobj->finaly[y][x] = -z + (x + y) * sin(0.523599) * ENLARGE;
			// fdfobj->finaly[y][x] *= 15;
			// fdfobj->finalx[y][x] *= 15;
			while (fdfobj->finaly[y][x] + fdfobj->offset < 30)
				fdfobj->offset += 10;
			if (fdfobj->grid[y][x] > fdfobj->test) // ova za proba e, trebit nekako da gi zemame najvisokite i najniskite
				fdfobj->test = fdfobj->grid[y][x];
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_horiz_lines(t_tabla *fdf, int x , int y)
{
	t_cpixels pixels;

	if (x + 1 < (int)fdf->gridlen)
	{
		pixels.startx = fdf->finalx[y][x] + fdf->offset;
		pixels.starty = fdf->finaly[y][x] + fdf->offset;
		pixels.endx = fdf->finalx[y][x + 1] + fdf->offset;
		pixels.endy = fdf->finaly[y][x + 1] + fdf->offset;

		pixels.end_color =  (fdf->colors[y][x + 1] != -1 ? 
			fdf->colors[y][x + 1] : get_default_color(fdf, fdf->grid[y][x + 1]));
		breshandler(pixels, fdf);
		// breshandler(fdf->finalx[y][x] + fdf->offset,
		// fdf->finaly[y][x] + fdf->offset, fdf->finalx[y][x + 1] + fdf->offset,
		// fdf->finaly[y][x + 1] + fdf->offset, fdf);
	}

}

void	draw_vert_lines(t_tabla *fdf, int x , int y)
{
	t_cpixels pixels;

	//fdf->colortest = 0xEF8633;
	if (y + 1 < (int)fdf->gridht)
	{
		pixels.startx = fdf->finalx[y][x] + fdf->offset;
		pixels.starty = fdf->finaly[y][x] + fdf->offset;
		pixels.endx = fdf->finalx[y + 1][x] + fdf->offset;
		pixels.endy = fdf->finaly[y + 1][x] + fdf->offset;

		pixels.end_color =  (fdf->colors[y + 1][x] != -1 ? 
			fdf->colors[y + 1][x] : get_default_color(fdf, fdf->grid[y + 1][x]));
		breshandler(pixels, fdf);
		// breshandler(fdf->finalx[y][x] + fdf->offset,
		// fdf->finaly[y][x] + fdf->offset, fdf->finalx[y + 1][x] + fdf->offset,
		// fdf->finaly[y + 1][x] + fdf->offset, fdf);
	}

}

void	drawgrid(t_tabla *fdfobj)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	getisocord(fdfobj);
	while (y < fdfobj->gridht)
	{
		fdfobj->orgy = y;
		while (x < fdfobj->gridlen)
		{
			fdfobj->orgx = x;
			draw_horiz_lines(fdfobj, x, y);
			draw_vert_lines(fdfobj, x , y);
			x++;
		}
		x = 0;
		y++;
	}
}
