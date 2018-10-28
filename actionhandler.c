/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:43:33 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 22:59:54 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "key_macros.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_tabla		*fdf;

	fdf = param;
	x = y;
	if (button == MOUSE_SCROLL_DOWN || button == MOUSE_SCROLL_UP)
	{
		zoom(button, fdf);
		return (0);
	}
	if (button == 1)
		fdf->mclicked += 1;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_tabla		*fdfobj;
	int			x1;
	int			y1;

	x1 = x;
	y1 = y;
	(void)button;
	fdfobj = param;
	fdfobj->mclicked = 0;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_tabla		*fdfobj;

	fdfobj = param;
	if (fdfobj->mclicked == 1)
	{
		fdfobj->view->projection = 'i';
		fdfobj->view->alpha += ((x - fdfobj->view->mouse_lastx) * 0.003);
		fdfobj->view->beta += ((y - fdfobj->view->mouse_lasty) * 0.003);
		generateimg(fdfobj);
	}
	fdfobj->view->mouse_lastx = x;
	fdfobj->view->mouse_lasty = y;
	return (0);
}

int		key_press(int keycode, void *param)
{
	t_tabla		*fdf;

	fdf = param;
	if (keycode == ESCAPE)
		exit(0);
	else if (keycode == NUM_PAD_MINUS || keycode == NUM_PAD_PLUS)
		zoom(keycode, fdf);
	else if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		move(keycode, fdf);
	else if (keycode >= NUM_PAD_1 && keycode <= NUM_PAD_9)
		rotate(keycode, fdf);
	else if (keycode == KEYBOARD_P || keycode == KEYBOARD_I)
	{
		fdf->view->alpha = 0;
		fdf->view->beta = 0;
		fdf->view->gamma = 0;
		fdf->view->projection = (keycode == KEYBOARD_P ? 'p' : 'i');
		generateimg(fdf);
	}
	else if (keycode == KEYBOARD_A || keycode == KEYBOARD_S)
		change_altitude(keycode, fdf);
	return (0);
}

int		close_app(void *param)
{
	t_tabla		*fdf;

	fdf = param;
	exit(0);
	return (0);
}
