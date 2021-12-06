/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao <joao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:16:07 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/26 23:42:30 by joao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_loop(char *r, char *current, int len);
char	*ft_initialize(int fd);
char	*ft_compile(int fd, char *r);
char	*ft_continue(char *r, int fd);

char	*get_next_line(int fd)
{
	static char	*b;
	char		*r;
	char		*temp;

	if (b != NULL)
	{
		r = ft_strdup(b);
		free(b);
		b = NULL;
	}
	else
	{
		r = ft_initialize(fd);
		if (r == NULL)
			return (NULL);
	}
	r = ft_continue(r, fd);
	if (ft_len(r) - ft_tr(r, '\n') > 1 && ft_tr(r, '\n') != -1)
	{
		b = ft_sub(r, ft_tr(r, '\n') + 1, ft_len(r) - ft_tr(r, '\n') - 1);
		temp = ft_sub(r, 0, ft_tr(r, '\n') + 1);
		free(r);
		return (temp);
	}
	return (r);
}

char	*ft_loop(char *r, char *current, int len)
{
	char	*temp;

	temp = ft_sub(r, 0, len);
	free(r);
	r = ft_strjoin(temp, current);
	free(temp);
	free(current);
	return (r);
}

char	*ft_initialize(int fd)
{
	char	*current;
	char	*r;
	int		no_read;

	current = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!current)
		return (0);
	if (fd < 0)
	{
		free(current);
		return (NULL);
	}
	no_read = read(fd, current, BUFFER_SIZE);
	current[no_read] = '\0';
	r = ft_strdup(current);
	free(current);
	if ((no_read == 0) || ft_len(r) == 0)
	{
		free(r);
		return (NULL);
	}
	return (r);
}

char	*ft_compile(int fd, char *r)
{
	int		no_read;
	int		len;
	char	*current;

	no_read = 1;
	len = ft_len(r);
	while (no_read > 0 && ft_tr(r, '\n') == -1)
	{
		current = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!current)
			return (0);
		no_read = read(fd, current, BUFFER_SIZE);
		current[no_read] = '\0';
		r = ft_loop(r, current, len);
		len = BUFFER_SIZE + len;
	}
	return (r);
}

char	*ft_continue(char *r, int fd)
{
	char	*temp;

	if ((ft_tr(r, '\n') == -1))
	{
		temp = ft_strdup(r);
		free(r);
		r = ft_compile(fd, temp);
	}
	return (r);
}
