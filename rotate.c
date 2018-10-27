/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 02:04:40 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/26 17:09:13 by jguleski         ###   ########.fr       */
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
			temx = x * view->zoom;
			temy = y * view->zoom;
			z = fdfobj->grid[y][x] * view->zoom; //ova za pogolema visina
			rotatex(view->alpha, &temy, &z);
			rotatey(view->beta, &temx, &z);
			rotatez(view->gamma, &temx, &temy);
			fdfobj->finalx[y][x] = (temx - temy) * cos(0.523599);// * ENLARGE;
			fdfobj->finaly[y][x] = -z + (temx + temy) * sin(0.523599);// * ENLARGE;
			while (fdfobj->finaly[y][x] + view->offset > HEIGHT) // problem mi prajt ova ko ke zumiram ne me ostavat da se vratam gore
				view->offset -= 30;
			x++;
		}
		y++;
		x = 0;
	}
}

		// while (fdfobj->finalx[y][x] + view->xoffset < 30)
		// 	view->xoffset += 10;