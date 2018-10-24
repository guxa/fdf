/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actionhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:43:33 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/20 19:25:25 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int mouse_press(int button, int x, int y, void *param)
{
	static int	x0;
	static int	y0;
	t_tabla		*tab;

	tab = param;
	if (tab->mclicked == 0 && button == 1)
	{
		x0 = x;
		y0 = y;
	}
	if (button == 1)
		((t_tabla*)param)->mclicked += 1;
	if (tab->mclicked == 2)
	{
		breshandler(x0, y0, x, y, tab);
		tab->mclicked = 0;
	}
	return (0);
}