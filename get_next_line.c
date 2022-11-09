/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:47:57 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/09 18:56:32 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stat_str;
	char		*temp;
	int			read_return;

	read_return = 1;
	while (read_return != 0)
	{
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return == -1)
			return (free(stat_str), NULL);
		buff[read_return] = '\0';
		if (!stat_str)
			stat_str = ft_strdup(buff);
		else
			stat_str = ft_strjoin(stat_str, buff);
		temp = ft_strdup(stat_str);
		if (!temp)
			return (free(stat_str), NULL);
		// printf("\nstat_string:%s", stat_str);
		// stat_str = find_and_change_stat(stat_str);
		if (check4newline(stat_str))
		{
			stat_str = update_stat_str(stat_str);
			return (get_line2(temp));
		}
	}
	return (get_line2(temp));
}

int	find_char(char *s, char c)
{
	int	i;

	i = 0;
	if (c == '\n')
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (i + 1);
			i++;
		}
		return (0);
	}
	else
		while (s[i])
			i++;
	return (i);
}

char	*get_line2(char	*temp)
{
	int		temp_end;
	int		i;
	char	*result;

	if (!temp)
		return (NULL);
	temp_end = find_char(temp, '\n');
	if (!temp_end)
		temp_end = find_char(temp, '\0');
	if (!temp_end)
		return(NULL);
	result = malloc(sizeof(char) * (temp_end + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (temp[i] && i < temp_end)
	{
		result[i] = temp[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);

	while (str)
	{
		printf("line:\t|%s|\n", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
	
}