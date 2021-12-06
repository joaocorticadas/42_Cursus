/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:52:32 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/30 16:48:54 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ubase(unsigned int nbr, char *base, int no);
int	ft_base(unsigned long nbr, char *base, int no);

//Functions to change bases

//For %u, %x and %X
int	ft_ubase(unsigned int nbr, char *base, int no)
{
	int				len;
	char			letter;
	unsigned long	cpy;

	cpy = nbr;
	letter = base[ft_strlen(base) - 1];
	len = 0;
	while (base[len] != '\0')
		len++;
	if (nbr < 0)
		ft_ubase(nbr, base, no);
	else if (nbr / len != 0)
	{
		ft_ubase((nbr / len), base, no);
		ft_putchar(base[nbr % len]);
	}
	else
		ft_putchar(base[nbr % len]);
	return (base_long_count(cpy, no));
}

//For %p
int	ft_base(unsigned long nbr, char *base, int no)
{
	int				len;
	char			letter;
	unsigned long	cpy;

	cpy = nbr;
	letter = base[ft_strlen(base) - 1];
	len = 0;
	while (base[len] != '\0')
		len++;
	if (nbr < 0)
		ft_base(nbr, base, no);
	else if (nbr / len != 0)
	{
		ft_base((nbr / len), base, no);
		ft_putchar(base[nbr % len]);
	}
	else
		ft_putchar(base[nbr % len]);
	return (base_long_count(cpy, no));
}
