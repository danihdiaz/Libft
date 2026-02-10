/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:07:06 by dhontani          #+#    #+#             */
/*   Updated: 2026/02/10 12:56:50 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			n;

	i = 0;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFF_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!has_newline(stash))
	{
		n = read(fd, buf, BUFF_SIZE);
		if (n == -1)
		{
			free(buf);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (n == 0)
			break ;
		buf[n] = '\0';
		stash = stash_join(buf, stash);
	}
	if (!stash)
	{
		free(buf);
		return (NULL);
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	free(buf);
	return (line);
}
