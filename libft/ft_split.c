/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseixo-c <jseixo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:57:29 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/09 10:20:40 by jseixo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *s, char c);
static int		ft_lettercount(char const *s, char c, int index);
static char		*ft_aloc(int a);
static void		ft_put_in(char const *s, char c, char **result_str);

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (((s[i] == c && s[i + 1] != c) && s[i + 1] != '\0')
			|| (s[i] != c && i == 0))
			wordcount++;
		i++;
	}
	return (wordcount);
}

static int	ft_lettercount(char const *s, char c, int index)
{
	int	lettercount;

	lettercount = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		index++;
		lettercount++;
	}
	return (lettercount);
}

static char	*ft_aloc(int a)
{
	char	*result;

	result = malloc((a + 1) * sizeof(char));
	if (!result)
		return (0);
	return (result);
}

static void	ft_put_in(char const *s, char c, char **result_str)
{
	int		i;
	int		j;
	int		k;
	int		a;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (((s[i] == c && s[i + 1] != c) && s[i + 1] != '\0')
			|| (s[i] != c && i == 0))
		{
			if (!(s[i] != c && i == 0))
				i++;
			a = ft_lettercount(s, c, i);
			result_str[j] = ft_aloc(a);
			k = -1;
			while (++k < a)
				result_str[j][k] = s[i++];
			result_str[j++][k] = '\0';
			continue ;
		}
		i++;
	}
	result_str[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result_str;

	result_str = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!result_str)
		return (0);
	ft_put_in(s, c, result_str);
	return (result_str);
}
