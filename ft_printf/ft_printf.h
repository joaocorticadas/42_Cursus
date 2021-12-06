/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:40:26 by joao              #+#    #+#             */
/*   Updated: 2021/11/30 16:46:44 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *c);
int	ft_putnbr(int n);
int	ft_base(unsigned long nbr, char *base, int no);
int	ft_strlen(char *c);
int	put_nbr_count(int n);
int	put_nbr_count(int n);
int	base_long_count(unsigned long n, int base);
int	ft_ubase(unsigned int nbr, char *base, int no);
int	ft_check(int i, const char *format, va_list arg_ptr);

#endif
