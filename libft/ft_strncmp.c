/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:07:14 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 19:16:46 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1u;
	unsigned char	*s2u;

	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (s1u[i] == s2u[i] && s1u[i] != 0 && i < n)
		i++;
	if (i == n)
		return (s1u[i - 1] - s2u[i - 1]);
	return (s1u[i] - s2u[i]);
}
