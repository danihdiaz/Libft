/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-20 16:27:58 by dhontani          #+#    #+#             */
/*   Updated: 2026-01-20 16:27:58 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
    const unsigned char *s1 = (const unsigned char *)s;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (s1[i])
    {
        i++;
    }
    char *dup = (char *) malloc(i + 1);
    if  (!dup)
        return (NULL);
    while (j <= i)
    {
        dup[j] = s1[j];
        j++;
    }
    return (dup);
}