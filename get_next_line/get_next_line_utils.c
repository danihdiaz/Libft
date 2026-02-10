/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:56:14 by dhontani          #+#    #+#             */
/*   Updated: 2026/02/10 20:03:43 by dhontani         ###   ########.fr       */
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

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	line[i] = '\0';
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
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
	size = strlen(stash + i + 1);
	temp = malloc(size + 1);
	if (!temp)
		return (NULL);
	size = 0;
	while (stash[i + 1 + size])
	{
		temp[size] = stash[i + 1 + size];
		size++;
	}
	temp[size] = '\0';
	free(stash);
	return (temp);
}
