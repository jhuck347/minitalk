/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:31:22 by jhuck             #+#    #+#             */
/*   Updated: 2024/01/18 01:03:13 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*byte_s1;
	const unsigned char	*byte_s2;

	byte_s1 = s1;
	byte_s2 = s2;
	i = 0;
	while (i < n)
	{
		if (byte_s1[i] != byte_s2[i])
			return (byte_s1[i] - byte_s2[i]);
		i++;
	}
	return (0);
}
