/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:36:29 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/12 13:15:22 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned char	cc;
	size_t			i;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == cc)
			return (unsigned char *)(cdst + (i + 1));
		i++;
	}
	return (NULL);
}
