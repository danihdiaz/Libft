/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhontani <dhontani@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-03 12:57:17 by dhontani          #+#    #+#             */
/*   Updated: 2026-02-03 12:57:17 by dhontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(va_list vargs);
int	ft_printstr(va_list vargs);
int	ft_printvoid(va_list vargs);
int	ft_putchar(char c);
int	ft_puthex(uintptr_t n);

#endif