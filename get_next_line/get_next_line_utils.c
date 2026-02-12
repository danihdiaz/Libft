/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:56:14 by dhontani          #+#    #+#             */
/*   Updated: 2026/02/11 20:29:43 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *stash)
{
	size_t	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 1 + (stash[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	size_t	i;
	size_t	size;
	char	*temp;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	size = ft_strlen(stash + i + 1);
	if (size == 0)
		return (free(stash), NULL);
	temp = malloc(size + 1);
	if (!temp)
		return (free(stash), NULL);
	size = 0;
	while (stash[i + 1 + size])
	{
		temp[size] = stash[i + 1 + size];
		size++;
	}
	temp[size] = '\0';
	return (free(stash), temp);
}

char	*stash_join(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!buffer)
		return (stash);
	if (!stash)
		tmp = malloc(ft_strlen(buffer) + 1);
	else
		tmp = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!tmp)
		return (free(stash), NULL);
	while (stash && stash[i])
	{
		tmp[i] = stash[i];
		i++;
	}
	while (buffer[j])
		tmp[i++] = buffer[j++];
	tmp[i] = '\0';
	return (free(stash), tmp);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
