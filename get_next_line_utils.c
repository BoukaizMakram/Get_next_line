/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:51:17 by mboukaiz          #+#    #+#             */
/*   Updated: 2022/11/13 10:36:57 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = ft_strlen(s1);
	dup = (char *)malloc((sizeof(char) * i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	int				i;

	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	while (n--)
	{
		destination[i] = source[i];
		i++;
	}
	return ((void *)dst);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*destination;
	char	*source;

	destination = (char *)dest;
	source = (char *)src;
	if (!src && !dest)
	{
		return (NULL);
	}
	if (destination >= source)
	{
		while (len)
		{
			len--;
			destination[len] = source[len];
		}
	}
	else
		ft_memcpy(destination, source, len);
	return ((void *)destination);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	size;

	size = ft_strlen(s);
	if (!s)
		return (NULL);
	if (size < start)
		len = 0;
	if (size - start < len)
		len = size - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	result = ft_memmove(result, s + start, len);
	return (result);
}
