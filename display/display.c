/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:41:03 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/08 16:48:17 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include "libft.h"

void	get_map_info(t_display *dis, char *line)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	dis->map_h = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	dis->map_l = ft_atoi(line + i);
}

int		get_info_and_fill(char *data, t_display *dis)
{
	int		ret;
	char	*line;
	int		line_cpt;

	line_cpt = 0;
	while ((ret = get_next_line(0, &line, 0)))
	{
		dis->term ? ft_putendl(line) : 0;
		if (line[0] == '=')
		{
			return (dis->finish = 1);
		}
		else if (ft_isdigit(line[0]) && line_cpt < dis->map_h)
			fill_data(line, data, dis, &line_cpt);
		if (line_cpt == dis->map_h)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (0);
}

int		boucle(void *param)
{
	t_display *dis;

	dis = (t_display *)param;
	if (dis->pause)
		return (0);
	dis->p1_played = 0;
	dis->p2_played = 0;
	get_info_and_fill(dis->data_ptr, dis);
	if (dis->finish)
		return (0);
	if (dis->s_p1)
		ft_itoa_score(dis->s_p1, dis->score_p1 + 8);
	if (dis->s_p2)
		ft_itoa_score(dis->s_p2, dis->score_p2 + 8);
	mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->img_ptr, 0, 0);
	if (dis->info)
		print_info(dis);
	return (0);
}

int		main(int ac, char **av)
{
	t_display	dis;

	init_data(&dis, av[0], ac >= 2 ? av[1] : NULL);
	mlx_hook(dis.w_ptr, 17, 0, close_x, &dis);
	mlx_hook(dis.w_ptr, 2, 0, key_press, &dis);
	mlx_loop_hook(dis.mlx_ptr, boucle, &dis);
	mlx_loop(dis.mlx_ptr);
	return (0);
}
