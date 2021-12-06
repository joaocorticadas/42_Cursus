/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:46:44 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/09 13:50:01 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && i < ft_strlen((char *)src))
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
		((char *)dst)[i] = '\0';
	}
	return (ft_strlen((char *)src));
}
