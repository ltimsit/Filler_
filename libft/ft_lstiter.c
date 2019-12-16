/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:05:40 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/07 19:45:53 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	f(lst);
	while (lst->next)
	{
		f(lst->next);
		lst = lst->next;
	}
}
