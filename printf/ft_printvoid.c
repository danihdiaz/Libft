/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-03 16:36:19 by dhontani          #+#    #+#             */
/*   Updated: 2026-02-03 16:36:19 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printvoid(va_list vargs)
{
	void		*c;
	uintptr_t	z;

	c = va_arg(vargs, void *);
	z = (uintptr_t)c;
	if (z == 0)
	{
		return (ft_putstr_fd("(nil)", 1), 5);
	}
	write(1, "0x", 2);
	return (ft_puthex(z) + 2);
}
