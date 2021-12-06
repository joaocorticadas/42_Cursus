/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:00:50 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/10/27 15:29:16 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < (count * size))
	{
		((unsigned char *)result)[i] = '\0';
		i++;
	}
	return (result);
}
