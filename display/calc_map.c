/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:00:42 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/06 19:00:10 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"

void	calc_size_block(t_display *dis)
{
	int size1;
	int size2;

	size1 = W_H / dis->map_h;
	size2 = W_L / dis->map_l;
	dis->b_size = size1 < size2 ? size1 : size2;
	dis->win_h = dis->b_size * dis->map_h;
	dis->win_l = dis->b_size * dis->map_l;
}

void	fill_block(t_display *dis, int *data, int color, t_coord coord)
{
	int x;
	int y;
	int x_max;
	int y_max;

	y = coord.y * dis->b_size + 1;
	y_max = y + dis->b_size - 1;
	while (y < y_max)
	{
		x = coord.x * dis->b_size + 1;
		x_max = x + dis->b_size - 1;
		while (x < x_max)
		{
			data[y * dis->win_l + x] = color;
			x++;
		}
		y++;
	}
}

int		get_color_and_score(char line, t_display *dis)
{
	int color;

	if (line == '.')
		color = 0xFF555555;
	else if (line == 'O')
		color = 0x00BB00;
	else if (line == 'o')
	{
		if (!(dis->p1_played++))
			dis->s_p1++;
		color = 0xEEFFEE;
	}
	else if (line == 'X')
		color = 0xFF0000;
	else if (line == 'x')
	{
		if (!(dis->p2_played++))
			dis->s_p2++;
		color = 0xFFEEEE;
	}
	else
		color = 0;
	return (color);
}

void	fill_data(char *line, char *data, t_display *dis, int *cpt)
{
	int		*data_i;
	int		i;
	int		j;
	int		color;
	t_coord	coord;

	data_i = (int *)data;
	i = 0;
	j = 0;
	coord.y = *cpt;
	while (line[i] && line[i] != '.' && line[i] != 'o' && line[i] != 'O'
			&& line[i] != 'x' && line[i] != 'X')
		i++;
	while (j < dis->map_l)
	{
		color = get_color_and_score(line[i + j], dis);
		coord.x = j;
		fill_block(dis, data_i, color, coord);
		j++;
	}
	(*cpt)++;
}
