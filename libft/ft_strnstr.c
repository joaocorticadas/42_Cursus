/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:28:33 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/09 11:56:54 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		pos;
	size_t	t;

	i = 0;
	if ((char)*needle == '\0')
		return ((char *)haystack);
	while (((char *)haystack)[i] != '\0' && i < len)
	{
		if (((char *)haystack)[i] == ((char *)needle)[0])
		{
			j = 0;
			pos = i;
			t = i;
			while (((char *)haystack)[t] == ((char *)needle)[j] && t < len &&
				((char *)haystack)[t] != '\0' &&
					((char *)needle)[j] != '\0' && ++t && ++j)
				if (j == ft_strlen(needle))
					return (&((char *)haystack)[pos]);
		}
		i++;
	}
	return (NULL);
}
