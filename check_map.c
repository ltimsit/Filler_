/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:38:16 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/08 18:37:13 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_line(t_data *data, char **line)
{
	int ret;

	ret = 0;
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	ret = get_next_line(0, line, 0);
	if (ret == -1)
		return (read_error(data, *line, 0));
	if (ret == 0)
		return (read_error(data, *line, 1));
	return (ret);
}

int	check_data(t_data *data)
{
	int		ret;
	char	*line;

	ret = 0;
	line = NULL;
	if (!data->number)
		if (!get_line(data, &line) || !get_player_info(line, data))
			return (player_error(data, line));
	if (!get_line(data, &line) || !get_map_info(line, data))
		return (map_error(data, 0, line));
	if (!get_line(data, &line))
		return (0);
	if (!fill_map(&line, data))
		return (map_error(data, 1, line));
	if (!get_line(data, &line) || !get_piece_info(line, data))
		return (piece_error(data, 0, line));
	if (!fill_piece(&line, data))
		return (piece_error(data, 1, line));
	free(line);
	return (1);
}
