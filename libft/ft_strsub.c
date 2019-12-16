/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:31:17 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/12 13:19:12 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	return (str);
}
