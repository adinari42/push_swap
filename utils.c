/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:39:25 by adinari           #+#    #+#             */
/*   Updated: 2022/07/10 16:29:23 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*mem_dup;
	size_t	i;

	i = 0;
	mem_dup = malloc(ft_strlen(s1) + 1);
	if (!mem_dup)
		return (NULL);
	while (s1[i] != '\0')
	{
		mem_dup[i] = s1[i];
		i++;
	}
	mem_dup[i] = '\0';
	return (mem_dup);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	l1;
	unsigned int	l2;

	if (!s)
		return (NULL);
	l1 = ft_strlen(s);
	l2 = ft_strlen(s + start);
	if (l1 < start)
		return (ft_strdup(""));
	if (l2 < len)
		len = ft_strlen(s + start);
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
