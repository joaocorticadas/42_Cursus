/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:24:38 by joao              #+#    #+#             */
/*   Updated: 2021/11/30 16:37:40 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c);
int	ft_putstr(char *c);
int	ft_putnbr(int n);
int	ft_strlen(char *c);

// For %c
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

/// For %s
int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[i] != '\0')
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}

/// For %d
int	ft_putnbr(int n)
{
	int	cpy;

	cpy = n;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (put_nbr_count(cpy));
}

//Aux function
int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}
