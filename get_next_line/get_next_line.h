/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao <joao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:00:24 by jseixo-c          #+#    #+#             */
/*   Updated: 2021/11/26 23:48:23 by joao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_tr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_len(const char *s);
char	*ft_sub(char const *s, unsigned int start, size_t len);
char	*ft_loop(char *res, char *current, int len);
char	*ft_initialize(int fd);
char	*ft_compile(int fd, char *res);
void	ft_last(char *res, char *buff);
char	*ft_continue(char *res, int fd);

#endif
