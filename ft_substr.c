/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:11:30 by dhontani          #+#    #+#             */
/*   Updated: 2026/01/24 18:58:12 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i != start && s[i] != '\0')
		i++;
	if (i == start)
	{
		while (s[i] && j < len)
		{
			p[j] = s[i];
			j++;
			i++;
		}
	}
	p[j] = '\0';
	return (p);
}
/*
int	main(void)
{
	printf("%s", ft_substr("abcdef", 3, 2));
}
*/