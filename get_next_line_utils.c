/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epesnel <epesnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:13:11 by epesnel           #+#    #+#             */
/*   Updated: 2025/11/21 14:25:51 by epesnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	altc;
	char	*alts;
	int		i;

	i = 0;
	alts = (char *)s;
	altc = c;
	while (alts[i] != altc)
	{
		if (alts[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)alts + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_blankstr(size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(sizeof(*temp) * (size + 1));
	if (!temp)
		return (NULL);
	while (i <= size)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	copy_len;
	char	*blank;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_blankstr(0));
	if (len > s_len - start)
		copy_len = s_len - start;
	else
		copy_len = len;
	blank = ft_blankstr(copy_len);
	if (!blank)
		return (NULL);
	i = 0;
	while (i < copy_len)
	{
		blank[i++] = s[start++];
	}
	return (blank);
}
