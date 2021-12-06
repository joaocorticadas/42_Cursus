/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:45:54 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/08 14:59:53 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cpy;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cpy = ft_lstlast(*lst);
	cpy->next = new;
}
