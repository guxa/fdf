/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:22:27 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/25 01:24:28 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_default_color(t_tabla *fdfobj, int z)
{
	double	percentage;

	percentage = percent(0, fdfobj->test, z); // ova colortest trebit da e max Z 
	if (percentage < 0.2)
		return (BLDBLUE);
	else if (percentage < 0.4)
		return (SCYAN);
	else if (percentage < 0.6)
		return (SCYAN);
	else if (percentage < 0.8)
		return (LGREEN);
	else
		return (PINK);
}

/*
** vo get pix colors, start color ne ja zemam zs e istata so cur color na pocetok
** kako so e uvideno i kaj vl.. ona so colortest e za da znam dali vleglo od
** draw-horiz-line ili draw-vert-line, zs ot to zavisit dali x+1 ili y + 1 
*/

// static void		get_pix_colors(int *cur_col, int *end_color, t_tabla *fdf)
// {
// 	int x;
// 	int y;

// 	x = fdf->orgx;
// 	y = fdf->orgy;
// 	cur_col = (fdf->colors[y][x] != -1 ? 
// 			fdf->colors[y][x] : get_default_color(fdf, fdf->grid[y][x]));
// 	end_color = (fdf->colortest < 0 ? fdf->grid[y + 1][x] : fdf->colortest);
// 	fdf->colortest = -1;

// }

int		get_color(t_tabla *fdfobj, t_cpixels pix, int cur_x, int cur_y)
{
	int		currentcol;
	double	percentage;
	int 	x;
	int		y;
	//int 	endcolor;

	x = fdfobj->orgx;
	y = fdfobj->orgy;
	currentcol = (fdfobj->colors[y][x] != -1 ? 
				fdfobj->colors[y][x] : get_default_color(fdfobj, fdfobj->grid[y][x]));
	
	if (FTABS(pix.endx - pix.startx) > FTABS(pix.endy - pix.starty))
		percentage = percent(pix.startx, pix.endx, cur_x);
	else
		percentage = percent(pix.starty, pix.endy, cur_y);



	// currentcol = percentage * get_default_color(fdfobj, fdfobj->grid[y][x])
	// 			+ (percentage - 1) * pix.end_color;
	
	return (currentcol);

	return (0);
}
