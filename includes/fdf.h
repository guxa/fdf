/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/28 00:02:03 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <../minilibx_macos/mlx.h>
# include <fcntl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <errno.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   FdF  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/

# define LGREEN 0x21FA90
# define PINK 0xD138BF
# define BLDBLUE 0x7494EA
# define SCYAN 0x44CCFF
# define SBLACK 0x0A0C16

# define ENLARGE 20
# define BPP 32
# define WIDTH 1200
# define HEIGHT 1000
# define MENU (WIDTH / 5)
# define FTABS(A) ((A) < 0 ? (-(A)) : (A))

typedef struct	s_view
{
	int			zoom;
	int			offset;
	int			xoffset;
	double		alpha;
	double		beta;
	double		gamma;
	int			mouse_lastx;
	int			mouse_lasty;
	char		projection;
	double		z_multiplier;
}				t_view;

typedef struct	s_cpixels
{
	int			startx;
	int			endx;
	int			starty;
	int			endy;
	int			cur_x;
	int			cur_y;
	int			end_color;
	int			st_color;
}				t_cpixels;

typedef struct	s_tabla
{
	void		*mlxptr;
	void		*winptr;
	int			mclicked;
	int			**grid;
	size_t		gridlen;
	size_t		gridht;
	int			**finalx;
	int			**finaly;
	int			maxz;
	void		*img;
	char		*data_add;
	int			size_line;
	int			endian;
	int			bpp;
	int			**colors;
	int			orgx;
	int			orgy;
	t_view		*view;
}				t_tabla;

typedef struct	s_fdflines
{
	char				*line;
	struct s_fdflines	*next;
}				t_fdflines;

void			clear_list(t_fdflines **head, char *laststr);
void			exit_app(const char *source);
void			initxyarr(t_tabla *fdfobj);
t_tabla			*tabinit(void);
void			change_altitude(int keycode, t_tabla *fdfobj);
void			paralelprojection(t_tabla *fdfobj);
int				close_app(void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			rotate(int key, t_tabla *fdfobj);
void			isoprojection(t_tabla *fdfobj);
void			zoom(int keycode, t_tabla *fdfobj);
void			move(int keycode, t_tabla *fdfobj);
t_view			*init_view(int gridlen, int gridht, int highest_alt);
int				key_press(int keycode, void *param);
int				get_default_color(t_tabla *fdfobj, int z);
t_cpixels		swap_pixels(t_cpixels pix);
int				get_color(t_cpixels pix, int cur_x, int cur_y);
void			insert_pixel(t_tabla *fdf, int x, int y, int color);
void			generateimg(t_tabla *fdfobj);
void			drawgrid(t_tabla *fdfobj);
void			makeintarr(t_fdflines *lista, t_tabla *fdfobj);
char			**ft_split(char *str);
int				checkresto(char **line, char **rest);
int				getlinija(int filedesc, char **line, char *buffer);
void			parsefdf(const char *filepath, t_tabla *fdfobj);
void			bresenhi(t_cpixels pix, t_tabla *ta);
void			breshandler(t_cpixels pix, t_tabla *ta);
int				mouse_press(int button, int x, int y, void *param);
void			bresenhaml(t_cpixels pix, t_tabla *ta);

#endif
