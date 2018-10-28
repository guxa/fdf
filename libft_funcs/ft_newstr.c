/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:27:07 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/14 19:38:16 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstr(size_t size)
{
	char	*newstr;

	newstr = (char *)malloc(sizeof(char) * size + 1);
	if (newstr == NULL)
		return (NULL);
	newstr[size] = '\0';
	return (newstr);
}
