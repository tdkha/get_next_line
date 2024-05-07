/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <kha.tieu@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:43:28 by ktieu             #+#    #+#             */
/*   Updated: 2024/05/07 09:04:26 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_next_line_break(char *str, size_t i)
{
	char	*ptr;

	ptr = str + i;
	while (*ptr && *ptr != '\n')
		ptr++;
	if (*ptr == '\n')
		ptr++;
	return (ptr - str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	tmp = (char *) s;
	res = (char *) malloc (sizeof(char) * len + 1);
	if (!res)
		return (0);
	while (tmp[i])
	{
		res[i] = tmp[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*ptr_res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ptr_res = res;
	while (*s1 != '\0')
	{
		*ptr_res++ = *s1++;
	}
	while (*s2 != '\0')
	{
		*ptr_res ++ = *s2++;
	}
	*ptr_res = '\0';
	free(s1);
	return (res);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *res;
        size_t  i;
        size_t  j;

        if (!s || start >= ft_strlen(s))
                len = 0;
        else if (len > ft_strlen(s) - start)
                len = ft_strlen(s) - start;
        res = (char *)malloc(sizeof(char) * (len + 1));
        if (!res)
                return (0);
        i = start;
        j = 0;
        while (i < ft_strlen(s) && j < len)
        {
                res[j] = s[i];
                j++;
                i++;
        }
        res[j] = '\0';
        return (res);
}
