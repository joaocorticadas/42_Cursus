/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:45:47 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:42 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set);
static int	ft_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		size;
	int		i;
	int		start;
	int		end;

	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (end < 0)
		size = 0;
	else
		size = ft_end(s1, set) - ft_start(s1, set) + 1;
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (start <= end)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[size] = '\0';
	return (result);
}

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	j;

	j = 0;
	start = 0;
	while (s1[j] != '\0')
	{
		if (start != j)
			break ;
		i = 0;
		while (set[i] != '\0')
		{
			if (set[i] == s1[j])
			{
				start++;
				break ;
			}
			i++;
		}
		j++;
	}
	return (start);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	j;

	j = (int)ft_strlen((char *)s1) - 1;
	end = (int)ft_strlen((char *)s1) - 1;
	while (j >= 0)
	{
		if (end != j)
		{
			break ;
		}
		i = 0;
		while (set[i] != '\0' && j >= 0)
		{
			if (set[i] == s1[j])
			{
				end--;
				break ;
			}
			i++;
		}
		j--;
	}
	return (end);
}
