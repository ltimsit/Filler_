/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:09:44 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 19:31:51 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] || needle[j] == 0)
		{
			if (needle[j] == 0)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
