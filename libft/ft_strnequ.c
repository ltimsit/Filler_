/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:27:31 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/11 19:18:45 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	if (i == n)
		i--;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
