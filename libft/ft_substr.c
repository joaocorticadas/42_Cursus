/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:18:41 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/09 13:48:22 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iterate(char const *s, unsigned int start, size_t len, int i);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		result_len;
	int		i;
	char	*result;

	result_len = ft_iterate(s, start, len, 0);
	if (start >= ft_strlen(s))
		result_len = 0;
	i = 0;
	result = malloc(result_len * sizeof(char) + 1);
	if (!result)
		return (0);
	if (start >= ft_strlen(s))
	{
		result[0] = '\0';
		return (result);
	}
	while (i < (int)len && s[start + i] != '\0' )
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	ft_iterate(char const *s, unsigned int start, size_t len, int i)
{
	while (i < (int)len && s[start + i] != '\0')
		i++;
	return (i);
}
