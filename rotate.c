/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 02:04:40 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 18:29:51 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rotate(int key, t_tabla *fdfobj)
{
	if (key == NUM_PAD_4)
		fdfobj->view->beta -= 0.05;
	else if (key == NUM_PAD_6)
		fdfobj->view->beta += 0.05;
	else if (key == NUM_PAD_2)
		fdfobj->view->alpha -= 0.05;
	else if (key == NUM_PAD_8)
		fdfobj->view->alpha += 0.05;
	else if (key == NUM_PAD_1)
		fdfobj->view->gamma -= 0.05;
	else if (key == NUM_PAD_9)
		fdfobj->view->gamma += 0.05;
	generateimg(fdfobj);
}

void	isoprojection(t_tabla *fdfobj)
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
			temx = x * fdfobj->view->zoom;
			temy = y * fdfobj->view->zoom;
			z = fdfobj->grid[y][x] * fdfobj->view->zoom * fdfobj->view->z_multiplier; //ova za pogolema visina
			rotatex(fdfobj->view->alpha, &temy, &z);
			rotatey(fdfobj->view->beta, &temx, &z);
			rotatez(fdfobj->view->gamma, &temx, &temy);
			fdfobj->finalx[y][x] = (temx - temy) * cos(0.523599);
			fdfobj->finaly[y][x] = -z + (temx + temy) * sin(0.523599);
			x++;
		}
		y++;
		x = 0;
	}
}

void	paralelprojection(t_tabla *fdfobj)
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
			z = fdfobj->grid[y][x] * fdfobj->view->zoom;
			fdfobj->finalx[y][x] = x * fdfobj->view->zoom;
			fdfobj->finaly[y][x] = y * fdfobj->view->zoom;
			rotatex(fdfobj->view->alpha, &(fdfobj->finaly[y][x]), &z);
			rotatey(fdfobj->view->beta, &(fdfobj->finalx[y][x]), &z);
			rotatez(fdfobj->view->gamma, &(fdfobj->finalx[y][x]), &(fdfobj->finaly[y][x]));
			x++;
		}
		y++;
		x = 0;
	}
}