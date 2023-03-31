/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:25:05 by cvu               #+#    #+#             */
/*   Updated: 2023/03/24 04:25:10 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	contains_newline(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join_strs(const char *s1, const char *s2)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_malloc_zero(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	while (s1 && s1[i])
		i++;
	s2 = ft_malloc_zero(i + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
	{
		s2[i] = s1[i];
	}
	return (s2);
}

void	*ft_malloc_zero(size_t count, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			total;
	size_t			i;

	total = count * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	i = 0;
	while (i < total)
	{
		p[i] = '\0';
		i++;
	}
	return (r);
}

void	ft_free_strs(char **str, char **str2, char **str3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}