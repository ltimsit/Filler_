/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:58:40 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/08 18:52:49 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**create_piece(t_data *data)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * data->b_height)))
		return (NULL);
	while (i < data->b_height)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char)
						* (data->b_length + 1))))
			return ((char **)free_all((void **)tab, i));
		tab[i][data->b_length] = '\0';
		i++;
	}
	return (tab);
}

int		**create_map(t_data *data)
{
	int i;
	int **tab;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * data->height)))
		return (NULL);
	while (i < data->height)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int)
						* data->length)))
			return ((int **)free_all((void **)tab, i));
		i++;
	}
	return (tab);
}

char	**fill_piece(char **line, t_data *data)
{
	int line_cpt;
	int j;
	int error;

	error = 0;
	line_cpt = 0;
	while (line_cpt < data->b_height)
	{
		j = -1;
		if (!get_line(data, line) && ++error)
			break ;
		while (++j < data->b_length && (*line)[j])
		{
			if ((*line)[j] == '.' || (*line)[j] == '*')
				data->piece[line_cpt][j] = (*line)[j];
			else
				return (NULL);
		}
		line_cpt++;
		if (j != data->b_length && ++error)
			break ;
	}
	if (error)
		return (NULL);
	return (data->piece);
}

int		get_piece_info(char *line, t_data *data)
{
	int i;

	i = 0;
	if (ft_strstr(line, "Piece") != line)
		return (0);
	while (line[i] < '0' || line[i] > '9')
		i++;
	if ((data->b_height = ft_atoi(line + i)) <= 0)
		return (0);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] < '0' || line[i] > '9')
		i++;
	if ((data->b_length = ft_atoi(line + i)) <= 0)
		return (0);
	if (!(data->piece = create_piece(data)))
		return (0);
	return (1);
}
