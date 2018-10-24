/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:22:27 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/24 16:25:20 by jguleski         ###   ########.fr       */
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

int		get_color(t_tabla *fdfobj, int x, int y)
{
	int currentcol;

	currentcol = (fdfobj->colors[y][x] != -1 ? 
					fdfobj->colors[y][x] : get_default_color(fdfobj, fdfobj->grid[y][x]));
	if (fdfobj->colortest == currentcol)
		return (currentcol);

	return 0;
}

int get_default_color(t_tabla *fdfobj, int z)
{
	double	percentage;

	percentage = fdfobj->z; //ova cisto sportski za compile bese staveno
	percentage = percent(0, 15, z);
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

