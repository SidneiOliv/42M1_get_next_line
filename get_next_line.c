/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-oliv <sde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:14:57 by sde-oliv          #+#    #+#             */
/*   Updated: 2025/01/03 12:24:54 by sde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_read(int fd, char *mem);
static char	*get_line(char *mem);
static char	*get_mem(char *mem);

char	*get_next_line(int fd)
{
	static char	*mem = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!mem)
	{
		mem = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (mem == NULL)
			return (NULL);
	}
	mem = get_read(fd, mem);
	if (!mem)
		return (free(mem), NULL);
	line = get_line(mem);
	if (!line)
		return (free(mem), NULL);
	mem = get_mem(mem);
	if (!mem)
		return (free(line), free(mem), NULL);
	return (line);
}

static char	*get_read(int fd, char *mem)
{
	char	*rd;
	int		nbf;

	nbf = 1;
	while (nbf > 0 && !(ft_strchr(mem, '\n')))
	{
		rd = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (rd == NULL)
			return (NULL);
		nbf = read(fd, rd, BUFFER_SIZE);
		if (nbf == -1)
			return (free(rd), free(mem), NULL);
		if (nbf == 0 && mem[0] != '\0')
			return (free(rd), mem);
		if (nbf == 0 && mem[0] == '\0')
			return (free(rd), free(mem), NULL);
		rd[BUFFER_SIZE] = '\0';
		mem = ft_strjoin2(mem, rd);
		if (!mem)
			return (free(rd), NULL);
		free(rd);
	}
	return (mem);
}

static char	*get_line(char *mem)
{
	char	*line;
	int		i;

	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	if (mem[i] == '\0')
		i--;
	line = ft_calloc((i + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
	{
		line[i] = mem[i];
		i++;
	}
	if (mem[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_mem(char *mem)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	j = i;
	while (mem[i] != '\0')
		i++;
	new = ft_calloc((i - j + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	if (mem[i] == '\n')
		i++;
	j = 0;
	while (mem[i] != '\0')
		new[j++] = mem[i++];
	new[j] = '\0';
	free (mem);
	return (new);
}
