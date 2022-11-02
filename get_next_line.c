/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 11:47:57 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/02 17:13:10 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*total_str;
	static char	buff[BUFFER_SIZE + 1];
	int		read_return;

	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	while (read_return != 0)
	{
		read_return = read(fd, s, BUFFER_SIZE);
		s[read_return] = '\0';
		printf("\n total string : %s", total_str);
		total_str = ft_strjoin(total_str, s);
		// s = get_current_line(s);
		printf("\n total string : %s", total_str);
	}
	return (total_str);
}

// char	*get_current_line(char *s)
// {
// 	static int	tracker;

// 	return(ft_strchr(s, '\n'));
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<fcntl.h> 

int	main()
{
	int	fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("\ns = %s", s);
	close(fd);
	return (0);
}