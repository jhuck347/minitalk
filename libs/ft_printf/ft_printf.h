/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:14:09 by jhuck             #+#    #+#             */
/*   Updated: 2024/02/08 02:12:19 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *format, ...);
void	checkformat(char format, va_list args, int *count);
void	ft_putchar(int c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbrbase16(unsigned long n, int upordw, int *count);
void	ft_putnbrbase10plus(unsigned int n, int *count);

#endif
