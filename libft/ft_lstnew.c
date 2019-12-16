/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:07:54 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/12 15:32:41 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlist->next = NULL;
	if (content)
	{
		if (!(newlist->content = malloc(sizeof(content) * content_size)))
		{
			free(newlist);
			return (NULL);
		}
		newlist->content = ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	else
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	return (newlist);
}
