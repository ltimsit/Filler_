/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:46:15 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 19:11:47 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1u;
	unsigned char	*s2u;

	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	i = 0;
	while (s1u[i] == s2u[i] && (s1u[i] != 0 && s2u[i] != 0))
	{
		i++;
	}
	return (s1u[i] - s2u[i]);
}
