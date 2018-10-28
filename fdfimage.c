/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:34:15 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/27 23:00:50 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

/*
** in insert_pixel check x > MENU, so when obj is moved it doesn't go over menu
** it just goes behind so user can still see the controls. size_line is num of
** ..bytes used to store 1 line of the image in memory i.e. WIDTH * (bpp / 8),
**  ..bpp/8 is number of bytes needed to store 1 pixel in our case it's 4 bytes
** with (y * size_line) we can reach any Y line, and insert pixels anywhere
*/

void		insert_pixel(t_tabla *fdf, int x, int y, int color)
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

/*
** init_view , zumot se inic standardno pa se  reducirat za ->
** (najvisokata tocka  * zum  + vert offset) da ne e nadvor od prozorot
** ako e <= 0, se vrakat na 1, zosto koord se * so zoom, i ke stanat 0
** xoffset e + MENU za centralna pozicija da imat obj na slobodniot prostor
*/

t_view		*init_view(int gridlen, int gridht, int highest_alt)
{
	t_view *uview;

	if ((uview = malloc(sizeof(t_view))) == NULL)
		exit_app("Malloc inside init_view() failed");
	uview->zoom = (WIDTH / gridlen <= HEIGHT / gridht ?
					(WIDTH - MENU) / gridlen / 2 : HEIGHT / gridht / 2);
	uview->zoom = (uview->zoom == 0 ? 1 : uview->zoom);
	uview->offset = (HEIGHT + gridht * uview->zoom) / 2;
	uview->xoffset = WIDTH / 2 + MENU / 2;
	while (-(highest_alt * uview->zoom) + uview->offset < 0)
		uview->zoom -= 1;
	uview->alpha = 0;
	uview->beta = 0;
	uview->gamma = 0;
	uview->projection = 'i';
	uview->zoom = (uview->zoom <= 0 ? 1 : uview->zoom);
	uview->z_multiplier = 1;
	while ((gridht - 1) * uview->zoom + uview->offset > HEIGHT)
		uview->offset -= 30;
	return (uview);
}

/*
** the s*it show below, is because of Norminette-ing reasons :)
*/

static void	print_menu(t_tabla *f, int s, int y)
{
	mlx_string_put(f->mlxptr, f->winptr, s, y, LGREEN, "Commands");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 50), LGREEN, "Zoom:");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "Mouse Scroll");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "Or Numpad + -");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 50), LGREEN, "Rotate:");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN,
		"Left click & move");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "Or Numpad:");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 20), SCYAN,
		"2/8 | 4/6 | 1/9");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 50), LGREEN, "Move:");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN,
		"ARROWS: UP DOWN");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "LEFT RIGHT");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 50), LGREEN,
		"Change altitude:");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "A -> Increase");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "S -> Decrease");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 50), LGREEN,
		"Change projection:");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "P -> Parallel");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "I -> Isometric");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 50), LGREEN, "<>Exit:");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "ESCAPE");
	mlx_string_put(f->mlxptr, f->winptr, s, (y += 25), SCYAN, "Close window");
}

/*
** generateimg, fills data_add with background colors, after that img is drawn
** by populating only those pixels where the lines are placed with appr colors
*/

void		generateimg(t_tabla *fdfobj)
{
	int i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		((int*)(fdfobj->data_add))[i] = (i % WIDTH <= MENU ?
											0x0A0C16 : 0x000000);
		i++;
	}
	drawgrid(fdfobj);
	mlx_put_image_to_window(fdfobj->mlxptr, fdfobj->winptr, fdfobj->img, 0, 0);
	print_menu(fdfobj, MENU / 10, MENU / 10);
}
