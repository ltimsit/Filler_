/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:50:09 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/12 13:18:08 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	ss1;
	size_t	ss2;

	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	if (!(str = ft_strnew(ss1 + ss2)))
		return (NULL);
	if (str)
	{
		ft_strcat(str, s1);
		ft_strcat(str, s2);
	}
	return (str);
}
