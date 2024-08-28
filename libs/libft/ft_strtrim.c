/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:16:31 by jhuck             #+#    #+#             */
/*   Updated: 2024/01/29 01:05:38 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstart(const char *s1, const char *set, int start)
{
	int	j;

	while (s1[start])
	{
		j = 0;
		while (set[j])
		{
			if (s1[start] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		start++;
	}
	return (start);
}

static int	checkend(const char *s1, const char *set, int end)
{
	int		j;

	while (end >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[end] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new_str;
	int		i;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = checkstart(s1, set, 0);
	end = checkend(s1, set, ft_strlen(s1) - 1);
	if (start > end)
		return (ft_strdup(""));
	new_str = (char *)malloc(end - start + 2);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}
