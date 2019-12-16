/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:32:03 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/09 11:36:26 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

uint32_t	diff(uint32_t a, uint32_t b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

void		place_player(char *data, int height, int length, int distance)
{
	uint32_t x_1;
	uint32_t y_1;
	uint32_t x_2;
	uint32_t y_2;

	if (distance > length + height)
		distance = length + height > 4 ? length + height - 4 : 1;
	x_1 = 0;
	y_1 = 0;
	x_2 = 0;
	y_2 = 0;
	while (diff(x_1, x_2) + diff(y_1, y_2) != (unsigned int)distance)
	{
		x_1 = arc4random_uniform(length);
		y_1 = arc4random_uniform(height);
		x_2 = arc4random_uniform(length);
		y_2 = arc4random_uniform(height);
	}
	data[y_1 * (length + 1) + x_1] = 'O';
	data[y_2 * (length + 1) + x_2] = 'X';
}

int			fill_file(int fd, int height, int length, int distance)
{
	int		x;
	int		y;
	char	*data;
	int		size;

	size = height * (length + 1);
	if (!(data = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	data[size] = '\0';
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < length)
		{
			data[y * (length + 1) + x] = '.';
			x++;
		}
		data[y * (length + 1) + x] = '\n';
		y++;
	}
	place_player(data, height, length, distance);
	ft_putstr_fd(data, fd);
	free(data);
	return (1);
}

int			get_fd(char *av0, char *av1, FILE **fileptr)
{
	char	path[256];
	int		fd;
	int		len;

	fd = 0;
	if (av0 && av0[0] == '.' && av0[1] == '/')
		av0 += 2;
	len = ft_strstr(av0, "map_gen") - av0;
	ft_strncpy(path, av0, len);
	path[len] = '\0';
	ft_strcat(path, "resources/maps/");
	ft_strcat(path, av1);
	*fileptr = fopen(path, "w");
	fd = open(path, O_WRONLY);
	return (fd);
}

int			main(int ac, char **av)
{
	int		fd;
	int		height;
	int		length;
	int		distance;
	FILE	*file_ptr;

	if (ac != 5)
	{
		ft_printf("{GREEN}usage : <NAME> <HEIGHT> <LENGTH> ");
		ft_printf("<STARTING_DISTANCE>{RESET}\n");
		return (0);
	}
	fd = get_fd(av[0], av[1], &file_ptr);
	height = ft_atoi(av[2]);
	length = ft_atoi(av[3]);
	distance = ft_atoi(av[4]);
	if (height <= 1 || length <= 1 || distance <= 0)
	{
		ft_printf("{RED}Bad input{RESET}%&\n", 2);
		return (0);
	}
	if (!(fill_file(fd, height, length, distance)))
		ft_printf("{RED}Malloc Error : could not create map{RESET}%&\n", 2);
	return (0);
}
