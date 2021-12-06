/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:55:16 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/10/27 16:19:12 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc((sizeof(char) * ft_strlen((char *)s1)) + 1);
	if (!result)
	{
		return (0);
	}
	while (i < ft_strlen((char *)s1))
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
