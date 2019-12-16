/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:20:20 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/08 18:52:44 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"
#include "mlx.h"
#include <pthread.h>

int		get_player_info(char *line, t_data *data)
{
	int			i;

	i = 0;
	if (!ft_strstr(line, "ltimsit"))
		return (0);
	while (line[i] && line[i] != 'p')
		i++;
	if (line[i] && line[i + 1] == '-')
		return (0);
	if (line[i] == 'p' && (data->number = ft_atoi(line + i + 1)) <= 2)
		return (data->number);
	return (0);
}

int		print_and_free_piece(t_data *data, t_coord *result)
{
	free_all((void **)data->piece, data->b_height);
	data->piece = NULL;
	if (!(ft_printf("%d %d\n", result->y, result->x)))
		return (0);
	return (1);
}

int		end(t_data *data)
{
	char *line;

	get_next_line(0, &line, 1);
	free_all((void **)data->map, data->height);
	return (0);
}

int		main(void)
{
	t_data	data;
	t_coord result;

	init_data_result(&data, &result);
	while (1)
	{
		data.line_nb = 0;
		data.b_line_nb = 0;
		if (!check_data(&data))
			return (0);
		if (data.map)
		{
			parse(&data);
			if (!result.finish)
				test_pos_block(&data, &result);
			if (result.finish)
				fill_rest_map(&data, &result);
			if (!(print_and_free_piece(&data, &result)))
				break ;
			if (result.filled)
				break ;
		}
	}
	return (end(&data));
}
