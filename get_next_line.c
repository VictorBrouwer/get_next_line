/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 11:47:57 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/01 14:40:02 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*total_str;
	char	*s;
	char	buff[BUFFER_SIZE];
	int		read_return;
	static int	tracker;

	while (read(fd, buff, BUFFER_SIZE) != 0)
	{
		s = malloc(BUFFER_SIZE + 1 * sizeof(char));
		read_return = read(fd, s, BUFFER_SIZE);
		s[read_return] = '\0';
		total_str = ft_strjoin(total_str, s);
	}
}
