/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:58:17 by jguleski          #+#    #+#             */
/*   Updated: 2018/10/17 22:41:10 by jguleski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinstr(const char *str1, const char *str2)
{
	char *result;

	result = NULL;
	if (str1 == 0 || str2 == 0)
		return (NULL);
	result = ft_newstr(ft_strlen(str1) + ft_strlen(str2));
	if (result)
	{
		ft_strcpy(result, str1);
		ft_strcat(result, str2);
		return (result);
	}
	else
		return (NULL);
}
