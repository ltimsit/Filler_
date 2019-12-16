/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:15:12 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/12 13:18:31 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	src_taille;

	src_taille = ft_strlen(src);
	i = 0;
	while (i < n)
	{
		if (i < src_taille)
			dest[i] = src[i];
		if (src_taille <= i)
			dest[i] = 0;
		i++;
	}
	return (dest);
}
