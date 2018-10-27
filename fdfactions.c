/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfactions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:15:56 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/26 18:16:07 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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