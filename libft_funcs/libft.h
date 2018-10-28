/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:05:04 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/28 00:15:09 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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

# define BUF_SIZE 20

char			*ft_joinstr(const char *str1, const char *str2);
char			*ft_strcat(char *dest, const char *string);

int				numberhandler(void *number, char type);
int				myprinter(const char *str, int start, int end);
int				findarg(const char *format, va_list ap);
int				parser(const char *format, va_list ap);
char			*ft_itoa_base(long number, int base);

void			ft_memdel(void **ap);
int				b_printf(const char *format, ...);
int				is_vartype(char c);
char			*cutstr(char const *inputstr, int start, int end);
char			*ft_newstr(size_t size);
int				countdigits(long number, int base);
int				myatoi_base(const char *str, int str_base);

void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_atoi(char *str);

char			*ft_strstr(const char *location, const char *target);
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
