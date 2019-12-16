/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:20:44 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/15 14:09:36 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
