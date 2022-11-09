/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:18:19 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/09 14:19:43 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *c);
char	*update_stat_str(char *s);
char	*get_line2(char	*temp);
char	*ft_strdup(char *s1);
void	*ft_memmove(void *dest, const void *src, size_t n);
int	check4newline(const char *s);

#endif // GET_NEXT_LINE