/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:33:03 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/23 17:12:20 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void iso(int x, int y, t_tabla *fdfobj)
{
	int z;

	z = fdfobj->grid[y][x] * 10;
	fdfobj->posx[y][x] = (x - y) * cos(0.523599) * ENLARGE; //cos(3.14159 / 6);
	fdfobj->posy[y][x] = -z + (x + y) * sin(0.523599) * ENLARGE; // sin(3.14159 / 6);
	// if (z == 0)
	// {
		// fdfobj->posx[y][x] = x;
		// fdfobj->posy[y][x] = y;
	// }
}

void	getisocord(t_tabla *fdfobj)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < (int)fdfobj->gridht)
	{
		while (x < (int)fdfobj->gridlen)
		{
			iso(x, y, fdfobj);
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_horiz_lines(t_tabla *fdfobj, int x , int y)
{
	fdfobj->colortest = 0xFFFFFF;
	if (x + 1 < (int)fdfobj->gridlen)
	{
		breshandler(fdfobj->posx[y][x], fdfobj->posy[y][x],
		fdfobj->posx[y][x + 1], fdfobj->posy[y][x + 1], fdfobj);
		// color begin
		// color end sranja
	}

}

void	draw_vert_lines(t_tabla *fdfobj, int x , int y)
{
	fdfobj->colortest = 0xFFFFFF;
	if (y + 1 < (int)fdfobj->gridht)
	{
		breshandler(fdfobj->posx[y][x], fdfobj->posy[y][x],
		fdfobj->posx[y + 1][x], fdfobj->posy[y + 1][x], fdfobj);
		// color begin
		// color end sranja
	}

}

void	drawgrid(t_tabla *fdfobj)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	getisocord(fdfobj);
	fdfobj->test = 5;  //ova da se izbrisit
	while (y < fdfobj->gridht)
	{
		//breshandler(x + 50, y * i, fdfobj->gridlen + 50, y * i, fdfobj);
		while (x < fdfobj->gridlen)
		{
			draw_horiz_lines(fdfobj, x, y);
			draw_vert_lines(fdfobj, x , y);
			x++;
		}

		x = 0;
		y++;
	}
}

//breshandler(x * SP + 10, y * SP + SP, (x + 1) * SP + 10, y * SP + SP, fdfobj);
//breshandler(x * SP + 10, y * SP + SP, x * SP + 10, (y + 1) * SP + SP, fdfobj);
