/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RAUL <RAUL@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:22:05 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/03/09 22:10:02 by RAUL             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	if (!(str = (char *)malloc(j + 1)))
		return (0);
	while (i < j)
	{
		str[i] = (char)s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 != 0 && s2 != 0)
	{
		i = ft_strlen(s1) + ft_strlen(s2) + 1;
		if (!(str = (char *)malloc(i)))
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = (char)s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			str[i + j] = (char)s2[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s != 0)
	{
		if (!(str = (char *)malloc(len + 1)))
			return (0);
		if (start > ft_strlen(s))
			return (ft_strdup(""));
		while (i < len && s[start] != '\0')
		{
			str[i] = (char)s[start];
			start++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
