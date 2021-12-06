/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:13:30 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/09 13:50:56 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_memsize(int n);

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	long	no;

	no = (long)n;
	i = ft_memsize(no) - 2;
	result = malloc(ft_memsize(no) * sizeof(char));
	if (!result)
		return (0);
	result[ft_memsize(no) - 1] = '\0';
	result[0] = '0';
	if (no < 0)
	{
		no = (-no);
		result[0] = '-';
	}
	while (no != 0)
	{
		result[i] = (no % 10) + '0';
		no /= 10;
		i--;
	}
	return (result);
}

static int	ft_memsize(int n)
{
	int	temp_no;
	int	i;

	temp_no = n;
	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (temp_no != 0)
	{
		temp_no = temp_no / 10;
		i ++;
	}
	i++;
	return (i);
}
