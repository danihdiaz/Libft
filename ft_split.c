/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:06:07 by dhontani          #+#    #+#             */
/*   Updated: 2026/01/26 21:13:24 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		wrd;
	char	**wrds;
	size_t	k;
	size_t	ini;

	i = 0;
	wrd = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				wrd++;
		}
		i++;
	}
	wrds = malloc((wrd + 1) * sizeof(char *));
	if (!wrds)
		return (NULL);
	k = 0;
	i = 0;
	ini = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				ini = i;
		}
		i++;
		if ((s[i] == c || s[i] == '\0') && (s[i - 1] != c))
		{
			wrds[k] = ft_substr(s, ini, (i - ini));
			if (!wrds[k])
			{
				while (k > 0)
				{
					free (wrds[k - 1]);
					k--;
				}
				free (wrds);
				return (NULL);
			}
			k++;
		}
	}
	wrds[k] = NULL;
	return (wrds);
}
