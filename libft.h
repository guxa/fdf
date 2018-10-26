/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/25 23:32:04 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <math.h>
# include <minilibx_macos/mlx.h>
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

# define BUF_SIZE 15
# define MYT -3

# define LGREEN 0x21FA90
# define PINK 0xD138BF
# define BLDBLUE 0x7494EA
# define SCYAN 0x44CCFF
# define SBLACK 0x494947
/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   FdF  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/
# define ENLARGE 20
# define BPP 32
# define WIDTH 1000
# define HEIGHT 1000
# define MENU 160
# define FTABS(A) ((A) < 0 ? (-(A)) : (A))

typedef struct	s_view
{
	int			zoom;
	int			offset;
	int			xoffset;
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
	int			colortest;
	int			**colors;
	int			orgx;
	int			orgy;
}				t_tabla;

typedef struct	s_fdflines
{
	char				*line;
	struct s_fdflines	*next;
}				t_fdflines;

int				get_default_color(t_tabla *fdfobj, int z);
t_cpixels		swap_pixels(t_cpixels pix);
int				get_color(t_tabla *fdfobj, t_cpixels pix, int cur_x, int cur_y);
//int				get_default_color(t_tabla *fdfobj, int z);
void			insert_pixel(t_tabla *fdf, int x, int y, int color);
void			generateimg(t_tabla *fdfobj);
void			drawgrid(t_tabla *fdfobj, t_view *view);
int				makeintarr(t_fdflines *lista, t_tabla *fdfobj);
char			**ft_split(char *str);
void			addtolist(void **head, void *element);
int				checkresto(char **line, char **rest);
int				getlinija(int filedesc, char **line, char *buffer);
int				parsefdf(const char *filepath, t_tabla *fdfobj);
void			bresenhi(t_cpixels pix, t_tabla *ta);
void			breshandler(t_cpixels pix, t_tabla *ta);
int				mouse_press(int button, int x, int y, void *param);
void			bresenhaml(t_cpixels pix, t_tabla *ta);

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> FILLER <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/

typedef struct	s_triler
{
	char		mychar;
	char		enchar;
	char		*line;
	char		*buffer;
	char		*rest;
	size_t		length;
	size_t		height;
	char		**map;
	size_t		theight;
	size_t		tlength;
	char		**token;
	size_t		x;
	size_t		y;
	char		*temp;
	int			bred;
	int			starfound;
	ssize_t		highscore;
	size_t		playx;
	size_t		playy;
	int			navigate;
}				t_triler;

void			clearmap(t_triler *filer);
ssize_t			tcenter(t_triler *fil, size_t firstx, size_t firsty);
void			checkstatus(t_triler *fi, int co, int x);
ssize_t			targetmid(t_triler *fil, size_t firstx, size_t firsty);
ssize_t			endcorner(t_triler *fil, size_t firstx, size_t firsty);
ssize_t			stcorner(t_triler *fil, size_t firstx, size_t firsty);
char			*ft_strstr(const char *location, const char *target);
int				checkscore(t_triler *fil, size_t firstx, size_t firsty);
int				checkbefore(t_triler *fi, ssize_t tx, ssize_t ty);
int				checkafter(t_triler *fi, size_t tx, size_t ty);
int				getnextstar(t_triler *fi, size_t *tx, size_t *ty);
int				shapepos(t_triler *fi);
int				checkoptions(t_triler *fi);
int				getpiece(int filedesc, t_triler *filer);
int				getmapinfo(t_triler *fil);
int				readmap(int filedesc, t_triler *filer);
int				getplayer(t_triler *filer);
void			initfiler(t_triler *filer);
char			*ft_joinstr(const char *str1, const char *str2);
//int				checkresto(t_triler *filer);

/*
** int				getlinija(int filedesc, t_triler *filer);
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> B_LS + REK <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/

typedef struct	s_afile
{
	struct timespec		fnano;
	mode_t				permisii;
	char				*name;
	int					linksnum;
	char				*user;
	char				*group;
	size_t				fsize;
	time_t				timemod;
	char				type;
	char				xattr;
	blkcnt_t			blocks;
	char				linkedfile[1024];
	struct s_afile		*next;

}				t_afile;

int				cmptime(t_afile *curr, t_afile *element);
int				sortjunk(char **argv, int argc, int flag, int x);
void			sortargvs(char **argv, int argc, int flag);
char			xattr(const char *path, t_afile *thefile);
void			getslink(const char *path, t_afile *thefile);
size_t			blockcounter(t_afile *alist);
void			clearlist(t_afile *head);
void			rtimesort(t_afile **head, t_afile *element);
void			timesort(t_afile **head, t_afile *element);
size_t			sizechecker(t_afile *alist);
void			printpermisii(mode_t filemode);
char			*getfilepath(const char *folder, const char *filename);
void			timeprinter(t_afile *dfile);
void			blsprinter(t_afile *filelist, const char *flags);
int				flagchecker(const char *flags);
void			revabcsort(t_afile **head, t_afile *element);
void			abcsort(t_afile **head, t_afile *element);
void			blslist(t_afile **head, t_afile *element, const char *flags);
t_afile			*fillelem(const char *path, char const *fname);
int				b_ls(const char *flags, const char *folder, int argc);
char			*ft_strcat(char *dest, const char *string);

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> B_PRINTF <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/

int				numberhandler(void *number, char type);
int				myprinter(const char *str, int start, int end);
int				findarg(const char *format, va_list ap);
int				parser(const char *format, va_list ap);
char			*ft_itoa_base(long number, int base);

typedef struct	s_strlist
{
	void				*data;
	int					argpos;
	int					is_arg;
	char				argtype;
	struct s_strlist	*next;

}				t_strlist;

void			listadd(t_strlist **mainlist, t_strlist *newelem);
t_strlist		*newlistelem(char const *inputstr, int start, int end);
t_strlist		*ft_add_elem(void *data);
int				b_printf(const char *format, ...);
int				is_vartype(char c);
void			oldlistadd(t_strlist **mainlist, const char *newstr);
char			*cutstr(char const *inputstr, int start, int end);
char			*ft_newstr(size_t size);
int				countdigits(long number, int base);
int				myatoi_base(const char *str, int str_base);
void			printhex(unsigned int x);

/*
** >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> B_LIB & STUFF <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*/
void			ft_memdel(void **ap);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_atoi(char *str);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memset(void *b, int c, size_t len);

#endif
