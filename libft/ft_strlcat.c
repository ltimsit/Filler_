/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:02:04 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/12 13:18:15 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	k = 0;
	while (src[k] && (i + k + 1) < size)
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = 0;
	if (size < i)
		return (j + size);
	return (i + j);
}
