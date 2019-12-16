/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:07:45 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/29 14:34:37 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"

void			free_and_exit_xpm(char **xpm, int i, char *path_xpm)
{
	if (path_xpm)
		free(path_xpm);
	while (--i >= 0)
	{
		free(xpm[i]);
	}
	free(xpm);
	exit(0);
}

void			free_and_end(t_display *dis)
{
	if (dis->img_ptr)
		free(dis->img_ptr);
	if (dis->name1)
		free(dis->name1);
	if (dis->name2)
		free(dis->name2);
	free(dis->xpm_img);
	free(dis->pause_xpm);
	free(dis->fond_xpm);
	free(dis->powb_xpm);
	free_and_exit_xpm(dis->xpm_tab, XPM_NB, NULL);
}

static void		filstr(long n, char *str, size_t size)
{
	int nb;

	nb = 0;
	str[size] = '\0';
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

char			*ft_itoa_score(int n, char *str)
{
	long	nc;
	size_t	size;

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
	filstr((long)n, str, size);
	return (str);
}

int				ft_abs(int a)
{
	return (a > 0 ? a : -a);
}
