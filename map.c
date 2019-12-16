/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 19:20:25 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/06 19:03:24 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	**free_all(void **data, int i)
{
	int j;

	j = 0;
	while (j < i)
		free(data[j++]);
	free(data);
	return (0);
}

int		init_fill_map(char *line, t_data *data)
{
	int i;

	i = 0;
	data->symbole = data->number == 1 ? 'O' : 'X';
	while (line[i] && line[i] != '\n' && line[i] != '.' && line[i] != 'X'
			&& line[i] != 'x' && line[i] != 'O' && line[i] != 'o')
		i++;
	if (!line[i] || line[i] == '\n')
		return (-1);
	return (i);
}

int		put_data_in_map(char *line, t_data *data, int j, int line_nb)
{
	if ((line[j] == 'O' || line[j] == 'o'))
	{
		if (data->number == 1)
			data->map[line_nb][j] = -2;
		else
			data->map[line_nb][j] = 0;
	}
	else if ((line[j] == 'X' || line[j] == 'x'))
	{
		if (data->number != 1)
			data->map[line_nb][j] = -2;
		else
			data->map[line_nb][j] = 0;
	}
	else if (line[j] == '.')
		data->map[line_nb][j] = -1;
	else
		return (0);
	return (1);
}

int		**fill_map(char **line, t_data *data)
{
	int line_cpt;
	int i;
	int j;
	int error;

	error = 0;
	i = 0;
	line_cpt = -1;
	while (++line_cpt < data->height)
	{
		j = 0;
		if (!get_line(data, line) && ++error)
			break ;
		if ((i = init_fill_map(*line, data)) == -1 && ++error)
			break ;
		while (j < data->length && (*line)[i + j])
			if (!(put_data_in_map(*line + i, data, j++, line_cpt))
					&& ++error)
				break ;
		if (j != data->length && ++error)
			break ;
	}
	if (error)
		return (0);
	return (data->map);
}

int		get_map_info(char *line, t_data *data)
{
	int i;

	i = 0;
	if (ft_strstr(line, "Plateau") != line)
		return (0);
	if (data->map)
		return (1);
	while (line[i] < '0' || line[i] > '9')
		i++;
	if ((data->height = ft_atoi(line + i)) <= 0)
		return (0);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] < '0' || line[i] > '9')
		i++;
	if ((data->length = ft_atoi(line + i)) <= 0)
		return (0);
	if (!(data->map = create_map(data)))
		return (0);
	return (1);
}
