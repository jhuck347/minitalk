/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:23:18 by jhuck             #+#    #+#             */
/*   Updated: 2024/02/08 02:12:52 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkformat(char format, va_list args, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbrbase16(va_arg(args, unsigned long), 0, count);
	}
	else if (format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_putnbrbase10plus(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_putnbrbase16(va_arg(args, unsigned int), 0, count);
	else if (format == 'X')
		ft_putnbrbase16(va_arg(args, unsigned int), 1, count);
	else if (format == '%')
		ft_putchar('%', count);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	count = 0;
	i = 0;
	va_start (args, format);
	while (format[i] && count != -1)
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			checkformat(format[i], args, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	return (count);
}
