/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:05:14 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/09 14:00:00 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	result = ft_strlen((char *)dst) + ft_strlen((char *)src);
	i = ft_strlen((char *)dst);
	j = 0;
	if (dstsize <= ft_strlen((char *)dst))
		return (ft_strlen((char *)src) + dstsize);
	if (dstsize != 0 && ft_strlen((char *)dst) <= dstsize)
	{
		while (i < (dstsize - 1) && ((char *)src)[j] != '\0')
		{
			((char *)dst)[i] = ((char *)src)[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (result);
}
