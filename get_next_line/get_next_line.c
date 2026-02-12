/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:07:06 by dhontani          #+#    #+#             */
/*   Updated: 2026/02/11 20:15:09 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_join(int fd, char *stash, char *buffer, int *eof)
{
	int		n;
	char	*tmp;

	n = read(fd, buffer, BUFFER_SIZE);
	if (n == -1)
		return (free(stash), NULL);
	if (n == 0)
	{
		*eof = 1;
		return (stash);
	}
	buffer[n] = '\0';
	tmp = stash_join(stash, buffer);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	eof = 0;
	while (!has_newline(stash) && !eof)
	{
		stash = read_and_join(fd, stash, buffer, &eof);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	return (free(buffer), line);
}
