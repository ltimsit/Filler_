/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:53:58 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/15 14:11:56 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
		{
			j++;
			if (s2[j] == 0)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
