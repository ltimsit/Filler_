/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:51:56 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 19:02:58 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memset(void *b, int c, size_t len)
{
	char			*bchar;
	unsigned char	cchar;

	bchar = (char *)b;
	cchar = (unsigned char)c;
	while (len--)
		*bchar++ = cchar;
	return (b);
}
