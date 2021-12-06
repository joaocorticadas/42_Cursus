/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:26:02 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/10/27 15:44:25 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (const char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((const char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
