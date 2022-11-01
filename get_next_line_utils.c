/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 14:19:22 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/01 14:37:10 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (res = ft_strdup(s2));
	if (!s2)
		return (res = ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, (len_s1 + len_s2 + 1));
	ft_strlcat(res, s2, (len_s1 + len_s2 + 1));
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

char	*ft_strdup(const char *s1)
{
	int		s1_len;
	int		x;
	char	*res;

	s1_len = ft_strlen(s1);
	res = malloc((s1_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	x = 0;
	while (x < s1_len)
	{
		res[x] = s1[x];
		x++;
	}
	res[x] = '\0';
	return (res);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	x = 0;
	y = dest_len;
	if (size < dest_len + 1)
		return ((src_len + size));
	if (size > 0 && dest_len < (size - 1))
	{
		while (src[x] && (dest_len + x) < (size - 1))
		{
			dest[y] = src[x];
			y++;
			x++;
		}
		dest[y] = '\0';
	}
	return ((dest_len + src_len));
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	x;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	x = 0;
	while (x < (count * size))
	{
		res[x] = '\0';
		x++;
	}
	return (res);
}