/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 23:50:57 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 23:03:43 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_tabla *fdfobj;

	if (argc < 2)
		exit_app("Invalid params\n Usage: ./fdf [map path]");
	fdfobj = tabinit();
	parsefdf(argv[1], fdfobj);
	initxyarr(fdfobj);
	fdfobj->view = init_view(fdfobj->gridlen, fdfobj->gridht, fdfobj->maxz);
	generateimg(fdfobj);
	mlx_hook(fdfobj->winptr, 4, 0, mouse_press, fdfobj);
	mlx_hook(fdfobj->winptr, 6, 0, mouse_move, fdfobj);
	mlx_hook(fdfobj->winptr, 5, 0, mouse_release, fdfobj);
	mlx_hook(fdfobj->winptr, 2, 0, key_press, fdfobj);
	mlx_hook(fdfobj->winptr, 17, 0, close_app, fdfobj);
	mlx_loop(fdfobj->mlxptr);
	return (0);
}
