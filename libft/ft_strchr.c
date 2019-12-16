/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:58:01 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 19:08:39 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strchr(const char *s, int c)
{
	char *str;
	char cc;

	str = (char *)s;
	cc = (char)c;
	while (*str)
	{
		if (*str == cc)
			return (str);
		str++;
	}
	if (*str == cc)
		return (str);
	return (NULL);
}
