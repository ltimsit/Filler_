/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:10:52 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 19:00:50 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n--)
	{
		if (*str++ == cc)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
