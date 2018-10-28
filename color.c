/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:22:27 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 23:00:04 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_default_color(t_tabla *fdfobj, int z)
{
	double	percentage;

	percentage = percent(0, fdfobj->maxz, z);
	if (percentage < 0.2)
		return (BLDBLUE);
	else if (percentage < 0.4)
		return (SCYAN);
	else if (percentage < 0.6)
		return (LGREEN);
	else if (percentage < 0.8)
		return (LGREEN);
	else
		return (PINK);
}

/*
** percentaGe is used for gradient, and value depends if we're drawing
** a vert or horiz line. Get RGB values & combine in single int for color
*/

int		get_color(t_cpixels pix, int cur_x, int cur_y)
{
	int		currentcol;
	double	percentage;
	int		red;
	int		green;
	int		blue;

	if (pix.st_color == pix.end_color)
		return (pix.end_color);
	if (FTABS(pix.endx - pix.startx) > FTABS(pix.endy - pix.starty))
		percentage = percent(pix.startx, pix.endx, cur_x);
	else
		percentage = percent(pix.starty, pix.endy, cur_y);
	red = (1 - percentage) * ((pix.st_color >> 16) & 0xFF) +
						(percentage * ((pix.end_color >> 16) & 0xFF));
	green = (1 - percentage) * ((pix.st_color >> 8) & 0xFF) +
						(percentage * ((pix.end_color >> 8) & 0xFF));
	blue = (1 - percentage) * (pix.st_color & 0xFF) +
						(percentage * (pix.end_color & 0xFF));
	currentcol = ((red << 16) | (green << 8) | blue);
	return (currentcol);
}
