/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 02:04:40 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 22:59:37 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "key_macros.h"

void	rotatex(double alpha, int *y, int *z)
{
	int prev_y;

	prev_y = *y;
	*y = *y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotatey(double beta, int *x, int *z)
{
	int prev_x;

	prev_x = *x;
	*x = *x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

void	rotatez(double gamma, int *x, int *y)
{
	int prev_y;
	int prev_x;

	prev_y = *y;
	prev_x = *x;
	*x = *x * cos(gamma) - *y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	isoprojection(t_tabla *fdf)
{
	int x;
	int y;
	int z;
	int temx;
	int temy;

	x = 0;
	y = 0;
	while (y < (int)fdf->gridht)
	{
		while (x < (int)fdf->gridlen)
		{
			temx = x * fdf->view->zoom;
			temy = y * fdf->view->zoom;
			z = fdf->grid[y][x] * fdf->view->zoom * fdf->view->z_multiplier;
			rotatex(fdf->view->alpha, &temy, &z);
			rotatey(fdf->view->beta, &temx, &z);
			rotatez(fdf->view->gamma, &temx, &temy);
			fdf->finalx[y][x] = (temx - temy) * cos(0.523599);
			fdf->finaly[y][x] = -z + (temx + temy) * sin(0.523599);
			x++;
		}
		y++;
		x = 0;
	}
}

void	paralelprojection(t_tabla *fdf)
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	while (y < (int)fdf->gridht)
	{
		while (x < (int)fdf->gridlen)
		{
			z = fdf->grid[y][x] * fdf->view->zoom;
			fdf->finalx[y][x] = x * fdf->view->zoom;
			fdf->finaly[y][x] = y * fdf->view->zoom;
			rotatex(fdf->view->alpha, &(fdf->finaly[y][x]), &z);
			rotatey(fdf->view->beta, &(fdf->finalx[y][x]), &z);
			rotatez(fdf->view->gamma, &(fdf->finalx[y][x]),
											&(fdf->finaly[y][x]));
			x++;
		}
		y++;
		x = 0;
	}
}
