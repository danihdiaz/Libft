/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:57:03 by dhontani          #+#    #+#             */
/*   Updated: 2026/02/11 20:29:34 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
# ifndef BUFF_SIZE
#  define BUFF_SIZE 42
# endif
*/
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		has_newline(char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
char	*stash_join(char *buffer, char *stash);
size_t	ft_strlen(const char *str);
char	*read_and_join(int fd, char *stash, char *buffer, int *eof);
char	*join_safe(char *stash, char *buffer);

#endif