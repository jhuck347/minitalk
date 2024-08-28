/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:11:25 by jhuck             #+#    #+#             */
/*   Updated: 2024/02/08 02:12:20 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *count)
{
	if (*count != -1)
	{
		if (write (1, &c, 1) != -1)
			*count += 1;
		else
			*count = -1;
	}
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
		ft_putstr("(null)", count);
	else
		while (*str)
			ft_putchar(*str++, count);
}

void	ft_putnbr(int n, int *count)
{
	if (n == INT_MIN)
		ft_putstr("-2147483648", count);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', count);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10, count);
		if (*count != -1)
			ft_putchar((n % 10) + '0', count);
	}
}

void	ft_putnbrbase16(unsigned long n, int upordw, int *count)
{
	if (n > 15)
		ft_putnbrbase16(n / 16, upordw, count);
	if (upordw == 1)
		ft_putchar("0123456789ABCDEF"[n % 16], count);
	else if (upordw == 0)
		ft_putchar("0123456789abcdef"[n % 16], count);
}

void	ft_putnbrbase10plus(unsigned int n, int *count)
{
	if (n > 9)
		ft_putnbrbase10plus(n / 10, count);
	if (*count != -1)
		ft_putchar((n % 10) + '0', count);
}
