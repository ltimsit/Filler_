/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:42:29 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/25 20:08:57 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		filstr(long n, char *str, size_t size)
{
	int nb;

	nb = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		nb = 1;
	}
	while (size - nb)
	{
		str[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	long	nc;
	size_t	size;
	char	*str;

	size = 1;
	if (n < 0)
	{
		size++;
		nc = -(long)n;
	}
	else
		nc = n;
	while (nc >= 10)
	{
		size++;
		nc = nc / 10;
	}
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (str)
		filstr((long)n, str, size);
	return (str);
}
