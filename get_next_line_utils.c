/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:19:22 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/09 18:58:02 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*update_stat_str(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			ft_memmove(&s[0], &s[i], (ft_strlen(s) - i));
			s[(ft_strlen(s) - i)] = '\0';
			return (s);
		}	
		i++;
	}
	if (i == 0)
		{
			
		}
	return (free(s), NULL);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*res;

	if (!s1)
		return (NULL);
	res = malloc((ft_strlen(s1) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	x;
	char	*char_src;
	char	*char_dest;

	char_src = (char *) src;
	char_dest = (char *) dest;
	x = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n-- > 0)
			char_dest[n] = char_src[n];
	}
	else
	{
		while (x < n)
		{
			char_dest[x] = char_src[x];
			x++;
		}
	}
	return (dest);
}

int	check4newline(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
