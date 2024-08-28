/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:21:59 by jhuck             #+#    #+#             */
/*   Updated: 2024/01/15 01:54:59 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	unsigned char	*memory;
	size_t			i;

	total_size = count * size;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
