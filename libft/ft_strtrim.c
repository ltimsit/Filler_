/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:09:48 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/15 13:56:33 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = ft_strlen(s);
	j = -1;
	while (i && (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t'))
		i--;
	while (i && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		s++;
		i--;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (++j < i && str)
		str[j] = s[j];
	return (str);
}
