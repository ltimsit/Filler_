/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <ltimsit-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:39:38 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/04/15 14:00:50 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void			*freeall(char **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(tab[i++]);
	}
	free(tab);
	return (NULL);
}

static size_t		nb_elem(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s && *s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

char				**ft_strsplit(const char *s, char c)
{
	size_t			i;
	size_t			j;
	unsigned int	start;
	char			**strtab;

	j = 0;
	start = 0;
	if (!(strtab = (char **)malloc(sizeof(char *) * nb_elem(s, c) + 1)))
		return (NULL);
	while (s[start])
	{
		i = 0;
		while (s[start] == c)
			start++;
		while (s[start + i] != c && s[start + i])
			i++;
		if (i)
			if (!(strtab[j++] = ft_strsub(s, start, i)))
				return (freeall(strtab, --j));
		start = start + i;
	}
	strtab[j] = NULL;
	return (strtab);
}
