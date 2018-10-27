/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:34:15 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/26 21:41:07 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		img_background(t_tabla *fdfobj)
{
	int i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		//  im[i] = ...
		//((int*)(fdfobj->data_add))[i] = (i < WIDTH * HEIGHT / 2 ? 0x222222 : 0x000000););
		((int*)(fdfobj->data_add))[i] = (i % WIDTH <= MENU ? 0x222222 : 0x000000); //0x9A1F6A
		i++;
	}
}
/*
** vo odnos na zumot, standardno se mestit sirina na ekran / sirina na mapa / 2
** posle kaj while loopot, provervit dali najvisokata tocka * zum + offset ke e
** pomala od 0, i ako to e slucajot go namalvit zumot
*/
t_view		*init_view(int gridlen, int gridht, int highest_alt)
{
	t_view *uview;

	if ((uview = malloc(sizeof(t_view))) == NULL)
		return (NULL);
	uview->zoom = (WIDTH / gridlen <= HEIGHT / gridht ?
					(WIDTH - MENU) / gridlen / 2 : HEIGHT / gridht / 2);
	uview->zoom = (uview->zoom == 0 ? 1 : uview->zoom);
	uview->offset = (HEIGHT + gridht * uview->zoom) / 2; // (HEIGHT + fdfobj->gridht * view->zoom)
	uview->xoffset = WIDTH / 2;
	while (-(highest_alt * uview->zoom) + uview->offset < 0)
		uview->zoom -= 1;
	uview->alpha = 0;
	uview->beta = 0;
	uview->gamma = 0;
	//uview->zoom = (uview->zoom <= 0 ? 1 : uview->zoom);
	return (uview);
}

static void		print_menu(t_tabla *fdfobj)
{
	int y;

	y = MENU / 10;

	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, y, LGREEN, "Commands");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 50), LGREEN, "Zoom:");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "Mouse Scroll");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "Or Numpad + -");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 50), LGREEN, "Rotate:");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "Press mouse & move");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "Or Numpad:");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 20), SCYAN, "2/8 | 4/6 | 1/9");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 50), LGREEN, "Move:");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "ARROW UP");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "ARROW DOWN");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "ARROW LEFT");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "ARROW RIGHT");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 50), LGREEN, "<>Exit:");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "ESCAPE");
	mlx_string_put(fdfobj->mlxptr, fdfobj->winptr, MENU / 10, (y += 25), SCYAN, "Close window");
}

void			generateimg(t_tabla *fdfobj)
{
	// t_view *uview;

	// uview = init_view(fdfobj->gridlen, fdfobj->gridht, fdfobj->maxz);
	img_background(fdfobj);
	drawgrid(fdfobj, fdfobj->view);
	mlx_put_image_to_window(fdfobj->mlxptr, fdfobj->winptr, fdfobj->img, 0, 0);
	print_menu(fdfobj);
}

void	insert_pixel(t_tabla *fdf, int x, int y, int color)
{
	int i;

	if (x > MENU && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->data_add[i] = color;
		fdf->data_add[++i] = color >> 8;
		fdf->data_add[++i] = color >> 16;
	}
}

// while (j < (mlx->bpp / 8))
//     {
//         *(mlx->addr + (mlx->lsize * y + ((mlx->bpp * x) / 8) + j)) = mlx->color >> (8 * j) & 0xff;
//         j++;
// 	}