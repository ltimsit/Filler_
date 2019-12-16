/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:36:37 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 18:56:10 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
