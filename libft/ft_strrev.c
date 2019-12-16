/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:21:29 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/15 12:46:32 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur_rev(char *str, size_t len)
{
	if (str < str + len)
	{
		ft_memswap(str, str + len);
		recur_rev(str + 1, len - 2);
	}
}

char		*ft_strrev(char *s)
{
	size_t len;

	len = ft_strlen(s);
	recur_rev(s, len - 1);
	return (s);
}
