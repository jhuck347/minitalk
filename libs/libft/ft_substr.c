/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:41:44 by jhuck             #+#    #+#             */
/*   Updated: 2024/01/28 21:58:02 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	subs_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	subs_len = len;
	if (start + len > ft_strlen(s))
		subs_len = ft_strlen(s) - start;
	subs = (char *)malloc(subs_len + 1);
	if (subs == NULL)
		return (NULL);
	ft_memcpy((void *)subs, ((const void *)(s + start)), subs_len);
	subs[subs_len] = '\0';
	return (subs);
}
