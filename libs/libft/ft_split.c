/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:51:19 by jhuck             #+#    #+#             */
/*   Updated: 2024/01/28 21:56:53 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	contchar(const char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if (!s[i])
		return (0);
	if (s[i] && s[0] != c)
		cont++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c && i != 0)
			cont++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cont);
}

static	int	contlenght(const char *s, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		lenght++;
	}
	return (lenght);
}

static	char	**freemalloc(char **dst, int i)
{
	while (i > 0)
	{
		i--;
		free(dst[i]);
	}
	free(dst);
	return (NULL);
}

static	char	**addmalloc(const char *s, char **dst, char c, int contmalloc)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < contmalloc)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = malloc(sizeof(char) * (contlenght(s, c, i) + 1));
		if (dst[j] == NULL)
			return (freemalloc(dst, j));
		while (s[i] && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		contmalloc;

	if (!s)
		return (NULL);
	contmalloc = contchar(s, c);
	dst = malloc(sizeof(char *) * (contmalloc + 1));
	if (dst == NULL)
		return (NULL);
	return (addmalloc (s, dst, c, contmalloc));
}
