/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lstlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:06:14 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/10/27 15:27:47 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cpy;
	int		i;
	int		times;

	cpy = lst;
	i = 0;
	while (cpy != NULL)
	{
		cpy = cpy->next;
		i++;
	}
	times = i - 1;
	i = 0;
	while (i < times)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
