/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-23 11:22:00 by dhontani          #+#    #+#             */
/*   Updated: 2026-01-23 11:22:00 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	mem1;
	size_t	mem2;
	char	*s;

	i = 0;
	j = 0;

	if (s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] == set[j])
			i++;
		if (s1[i] != set[j] && set[j] == '\0')
			break ;
	}
	mem1 = i;
	while (s1[i])
		i++;
	while (i > mem1)
	{
		j = 0;
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] == set[j])
			i--;
		if (s1[i] != set[j] && set[j] == '\0')
			break ;
	}
	mem2 = i;
	s = malloc(mem2 - mem1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && s[i] == set)
		i++;
	while (s1[i] && s1[i] != set)
	{
		s[j] = s1[i];
		j++;
		i++;
	}
	s[j] = '\0';
	return (s);
}