/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:35:03 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 18:55:31 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nextlst;
	t_list	*liststart;

	liststart = *alst;
	while (*alst)
	{
		nextlst = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = nextlst;
	}
	liststart = NULL;
}
