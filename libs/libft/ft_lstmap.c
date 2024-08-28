/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:33:00 by jhuck             #+#    #+#             */
/*   Updated: 2024/01/29 01:38:56 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;
	void	*cont;

	head = NULL;
	while (lst)
	{
		cont = f(lst->content);
		if (!cont)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp = ft_lstnew(cont);
		if (!tmp)
		{
			free(cont);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
