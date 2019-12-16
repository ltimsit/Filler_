/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 18:09:18 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/06 18:36:19 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		free_l(char *line)
{
	free(line);
	return (0);
}

void	init_data_result(t_data *data, t_coord *result)
{
	data->map = NULL;
	data->piece = NULL;
	data->line_nb = 0;
	data->b_line_nb = 0;
	data->length = 0;
	data->b_length = 0;
	data->height = 0;
	data->b_height = 0;
	data->en_symb = '0';
	data->number = 0;
	result->finish = 0;
	result->filled = 0;
}

void	init_coord(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
	coord->filled = 0;
	coord->finish = 0;
}
