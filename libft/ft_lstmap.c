/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:57:33 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/07 19:45:52 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newelem;
	t_list	*elem;

	if (!(elem = f(lst)))
		return (NULL);
	newelem = elem;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newelem->next = f(lst)))
			return (NULL);
		newelem = newelem->next;
	}
	return (elem);
}
