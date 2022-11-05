/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 11:47:57 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/05 14:41:57 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*temp;
	int			read_return;

	temp = ft_calloc(1);
	while (ft_strchr(temp, '\n') == NULL && read_return != 0)
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return == -1)
			return (NULL);
		buff[read_return] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	return (temp);
}


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