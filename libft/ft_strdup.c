/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:58:04 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/15 13:54:48 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = ft_strnew(ft_strlen(s1))))
		return (NULL);
	while (*s1 && dest)
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	if (dest)
		dest[i] = '\0';
	return (dest);
}
