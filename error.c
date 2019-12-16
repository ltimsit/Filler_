/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:21:58 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/08 14:28:46 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"

int		player_error(t_data *data, char *line)
{
	if (data->map)
	{
		free_all((void **)data->map, data->height);
		data->map = NULL;
	}
	if (data->piece)
	{
		free_all((void **)data->piece, data->b_height);
		data->piece = NULL;
	}
	ft_putstr_fd("\033[31mBad player info\033[0m\n", 2);
	get_next_line(0, &line, 1);
	if (line)
		free(line);
	return (0);
}

int		map_error(t_data *data, int type, char *line)
{
	if (data->map)
	{
		free_all((void **)data->map, data->height);
		data->map = NULL;
	}
	if (data->piece)
	{
		free_all((void **)data->piece, data->b_height);
		data->piece = NULL;
	}
	if (type == 0 && line)
		ft_putstr_fd("\033[31mBad map info\033[0m\n", 2);
	if (type == 1)
		ft_putstr_fd("\033[31mBad map data\033[0m\n", 2);
	get_next_line(0, &line, 1);
	if (line)
		free(line);
	return (0);
}

int		piece_error(t_data *data, int type, char *line)
{
	if (data->map)
	{
		free_all((void **)data->map, data->height);
		data->map = NULL;
	}
	if (data->piece)
	{
		free_all((void **)data->piece, data->b_height);
		data->piece = NULL;
	}
	if (type == 0)
		ft_putstr_fd("\033[31mBad piece info\033[0m\n", 2);
	if (type == 1)
		ft_putstr_fd("\033[31mBad piece data\033[0m\n", 2);
	get_next_line(0, &line, 1);
	if (line)
		free(line);
	return (0);
}

int		read_error(t_data *data, char *line, int option)
{
	if (data->map)
	{
		free_all((void **)data->map, data->height);
		data->map = NULL;
	}
	if (data->piece)
	{
		free_all((void **)data->piece, data->b_height);
		data->piece = NULL;
	}
	if (line)
		free(line);
	if (option == 0)
		ft_putstr_fd("\033[31mRead error\033[0m\n", 2);
	else
		ft_putstr_fd("\033[31mNothing to read\033[0m\n", 2);
	return (0);
}
