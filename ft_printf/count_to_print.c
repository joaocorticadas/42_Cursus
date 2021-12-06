/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_to_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:02:12 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/30 16:38:03 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_long_count(unsigned long n, int base);
int	put_nbr_count(int n);

//To count the number of char in int base functions
int	put_nbr_count(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

//To count the number of char in long base functions
int	base_long_count(unsigned long n, int base)
{
	int	i;
	int	cpy;

	cpy = n;
	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
