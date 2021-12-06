/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:13:15 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/10/27 15:27:12 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cpy;

	while (*lst != NULL)
	{
		cpy = (*lst)->next;
		del ((*lst)->content);
		free(*lst);
		*lst = cpy;
	}
	lst = NULL;
}
