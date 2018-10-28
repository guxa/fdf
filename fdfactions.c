/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfactions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:15:56 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 23:00:46 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "key_macros.h"

void	move(int keycode, t_tabla *fdfobj)
{
	if (keycode == ARROW_LEFT)
		fdfobj->view->xoffset -= WIDTH / 50;
	else if (keycode == ARROW_RIGHT)
		fdfobj->view->xoffset += WIDTH / 50;
	if (keycode == ARROW_UP)
		fdfobj->view->offset -= HEIGHT / 50;
	else if (keycode == ARROW_DOWN)
		fdfobj->view->offset += HEIGHT / 50;
	generateimg(fdfobj);
}

void	zoom(int keycode, t_tabla *fdfobj)
{
	if (keycode == NUM_PAD_PLUS || keycode == MOUSE_SCROLL_UP)
		fdfobj->view->zoom++;
	if (keycode == NUM_PAD_MINUS || keycode == MOUSE_SCROLL_DOWN)
		fdfobj->view->zoom--;
	if (fdfobj->view->zoom < 1)
		fdfobj->view->zoom = 1;
	generateimg(fdfobj);
}

void	change_altitude(int keycode, t_tabla *fdfobj)
{
	if (keycode == KEYBOARD_A)
		fdfobj->view->z_multiplier += 0.1;
	else
		fdfobj->view->z_multiplier -= 0.1;
	generateimg(fdfobj);
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
