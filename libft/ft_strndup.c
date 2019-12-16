/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:40:05 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/15 13:55:19 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = ft_strnew(ft_strnlen(s1, n))))
		return (NULL);
	while (*s1 && n-- && dest)
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	if (dest)
		dest[i] = '\0';
	return (dest);
}
