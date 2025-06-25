/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:00:33 by juhuck            #+#    #+#             */
/*   Updated: 2025/06/25 18:00:35 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	p;

	srcsize = ft_strlen(src);
	p = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (src[p] != '\0' && p < (dstsize - 1))
		{
			dst[p] = src[p];
			p++;
		}
		dst[p] = '\0';
	}
	return (srcsize);
}
