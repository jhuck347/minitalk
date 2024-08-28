/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:36:14 by jhuck             #+#    #+#             */
/*   Updated: 2024/01/25 00:42:31 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contlen(int n)
{
	int	lenn;

	lenn = 1;
	while (n > 9)
	{
		lenn++;
		n = n / 10;
	}
	return (lenn);
}

static char	*addmalloc(int n, int lenn, int sign)
{
	char	*strn;

	strn = malloc(sizeof(char) * (lenn + 1 + sign));
	if (strn == NULL)
		return (NULL);
	if (sign == 1)
	{
		strn[0] = '-';
		lenn++;
	}
	strn[lenn--] = '\0';
	while (n > 0)
	{
		strn[lenn] = (n % 10) + '0';
		lenn--;
		n = n / 10;
	}
	return (strn);
}

char	*ft_itoa(int n)
{
	int	copy;
	int	sign;
	int	lenn;

	copy = n;
	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		copy = -n;
		sign = 1;
	}
	lenn = contlen(copy);
	return (addmalloc(copy, lenn, sign));
}
