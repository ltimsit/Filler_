/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 12:06:20 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/06 19:02:59 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		block_on_heat_map(t_data *data, int x_m, int y_m, int val)
{
	int x;
	int y;
	int tot;
	int cpt;

	y = -1;
	tot = 0;
	cpt = 0;
	while (++y < data->b_height)
	{
		x = -1;
		while (++x < data->b_length)
		{
			if (data->piece[y][x] == '*' && (y + y_m < 0
						|| y + y_m >= data->height || x + x_m < 0
						|| x + x_m >= data->length
						|| (data->map[y + y_m][x + x_m] == -2 && cpt++ > 1)
						|| data->map[y + y_m][x + x_m] == 0))
				return (val);
			else if (data->piece[y][x] == '*'
					&& data->map[y + y_m][x + x_m] != -2)
				tot += data->map[y + y_m][x + x_m];
		}
	}
	return (cpt == 1 ? tot : val);
}

void	fill_rest_map(t_data *data, t_coord *coord)
{
	int x;
	int y;

	y = -(data->b_height);
	init_coord(coord);
	while (++y < data->height)
	{
		x = -(data->b_height);
		while (++x < data->length)
		{
			if (block_on_heat_map(data, x, y, 1 < 1))
			{
				coord->x = x;
				coord->y = y;
				return ;
			}
		}
	}
	coord->filled = 1;
}

void	test_pos_block(t_data *data, t_coord *coord)
{
	int x;
	int y;
	int ret;
	int val;

	ret = 0;
	y = -(data->b_height);
	val = 50000;
	init_coord(coord);
	while (++y < data->height)
	{
		x = -(data->b_height);
		while (++x < data->length)
		{
			if ((ret = block_on_heat_map(data, x, y, val)) < val && ret >= 0)
			{
				val = ret;
				coord->x = x;
				coord->y = y;
			}
		}
	}
	if (val == 50000)
		coord->finish = 1;
}

int		test_pos(t_data *data, int x, int y, int val)
{
	if (data->map[y][x] == -1
			&& ((x < data->length - 1 && data->map[y][x + 1] == val - 1)
				|| (x > 0 && data->map[y][x - 1] == val - 1)
				|| (x < data->length - 1 && y < data->height - 1
					&& data->map[y + 1][x + 1] == val - 1)
				|| (x > 0 && y < data->height - 1
					&& data->map[y + 1][x - 1] == val - 1)
				|| (x < data->length - 1 && y > 0
					&& data->map[y - 1][x + 1] == val - 1)
				|| (x > 0 && y > 0 && data->map[y - 1][x - 1] == val - 1)
				|| (y < data->height - 1 && data->map[y + 1][x] == val - 1)
				|| (y > 0 && data->map[y - 1][x] == val - 1)))
	{
		data->map[y][x] = val;
		return (1);
	}
	else
		return (0);
}

int		parse(t_data *data)
{
	int x;
	int y;
	int start;
	int val;
	int cpt;

	start = 1;
	val = 1;
	while (start || cpt)
	{
		cpt = 0;
		start = 0;
		y = -1;
		while (++y < data->height)
		{
			x = -1;
			while (++x < data->length)
			{
				if (test_pos(data, x, y, val))
					cpt = 1;
			}
		}
		val++;
	}
	return (0);
}
