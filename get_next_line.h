/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 10:18:19 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/01 14:41:18 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#if !defined(BUFFER_SIZE)
#define BUFFER_SIZE 1024

#endif

#if !defined(GET_NEXT_LINE_H)
#define GET_NEXT_LINE_H

#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);


#endif // GET_NEXT_LINE
