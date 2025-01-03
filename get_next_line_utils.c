/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:15:49 by sde-oliv          #+#    #+#             */
/*   Updated: 2025/01/03 12:24:50 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(int num, int size)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (num * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*news;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	news = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	while (s1[i2])
		news[i1++] = s1[i2++];
	i2 = 0;
	while (s2[i2])
		news[i1++] = s2[i2++];
	news[i1] = '\0';
	free(s1);
	return (news);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
