/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:50:38 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/06 19:02:17 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include "libft.h"

void	init_xpm_info(t_display *dis)
{
	char **tab;

	tab = dis->xpm_name;
	dis->xpm_file_nb = XPM_NB;
	tab[0] = "images/fcool.xpm";
	tab[1] = "images/pause.xpm";
	tab[2] = "images/fond.xpm";
	tab[3] = "images/powb.xpm";
	tab[4] = "images/snapshot.xpm";
}

void	init_xpm_tab(t_display *dis, char *path)
{
	char	*p_start;
	char	*path_xpm;
	int		i;

	i = -1;
	p_start = ft_strstr(path, "display_filler");
	path_xpm = ft_strsub(path, 0, p_start - path);
	if (!(dis->xpm_tab = (char **)malloc(sizeof(dis->xpm_tab) * XPM_NB)))
		free_and_exit_xpm(dis->xpm_tab, 0, path_xpm);
	while (++i < dis->xpm_file_nb)
		if (!(dis->xpm_tab[i] = ft_strjoin(path_xpm, dis->xpm_name[i])))
			free_and_exit_xpm(dis->xpm_tab, i, path_xpm);
	free(path_xpm);
}

char	*get_data_ptr(void *img_ptr)
{
	char	*data_ptr;
	int		bit_pp;
	int		size_line;
	int		endian;

	data_ptr = mlx_get_data_addr(img_ptr, &bit_pp, &size_line, &endian);
	return (data_ptr);
}

void	init_xpm(t_display *dis)
{
	int a;
	int b;

	dis->xpm_img = mlx_xpm_file_to_image(dis->mlx_ptr,
			dis->xpm_tab[0], &a, &b);
	dis->pause_xpm = mlx_xpm_file_to_image(dis->mlx_ptr,
			dis->xpm_tab[1], &a, &b);
	dis->fond_xpm = mlx_xpm_file_to_image(dis->mlx_ptr,
			dis->xpm_tab[2], &a, &b);
	dis->powb_xpm = mlx_xpm_file_to_image(dis->mlx_ptr,
			dis->xpm_tab[3], &a, &b);
	dis->ppause_xpm = mlx_xpm_file_to_image(dis->mlx_ptr,
			dis->xpm_tab[4], &a, &b);
	fill_background(dis);
}

void	init_data(t_display *dis, char *path, char *option)
{
	dis->term = option && ft_strcmp(option, "-term") == 0 ? 1 : 0;
	dis->mlx_ptr = mlx_init();
	dis->finish = 0;
	dis->s_p1 = 0;
	dis->s_p2 = 0;
	dis->map_h = 0;
	dis->map_l = 0;
	dis->name1 = NULL;
	dis->name2 = NULL;
	dis->pause = 0;
	dis->disable_p = 1;
	dis->info = 1;
	init_xpm_info(dis);
	init_xpm_tab(dis, path);
	get_player_and_map(dis);
	if (!dis->map_h || !dis->map_l || !dis->name1 || !dis->name2)
		free_and_end(dis);
	ft_strcpy(dis->score_p1, "SCORE : 0");
	ft_strcpy(dis->score_p2, "SCORE : 0");
	dis->w_ptr = mlx_new_window(dis->mlx_ptr, dis->win_l, dis->win_h,
			"Display");
	dis->img_ptr = mlx_new_image(dis->mlx_ptr, dis->win_l, dis->win_h);
	dis->data_ptr = get_data_ptr(dis->img_ptr);
	init_xpm(dis);
}
