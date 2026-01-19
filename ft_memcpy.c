/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-19 14:33:36 by dhontani          #+#    #+#             */
/*   Updated: 2026-01-19 14:33:36 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    unsigned char *d = (unsigned char *)dst
    unsigned char *s = (unsigned char *)src

    i = 0;
    while (i < n)
    {    
        d[i] = s[i];
        i++; 
    }
    return (dst);
}