/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:29:23 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/06 19:01:34 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include <unistd.h>

int		close_x(void *param)
{
	t_display *dis;

	dis = (t_display *)param;
	free_and_end(dis);
	return (0);
}

void	refresh_screen(t_display *dis)
{
	fill_background(dis);
	mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->img_ptr, 0, 0);
	if (dis->info)
		print_info(dis);
}

void	pause_no_info(t_display *dis)
{
	fill_background(dis);
	mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->img_ptr, 0, 0);
	if (dis->pause)
		mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->pause_xpm,
				dis->win_l / 2 - 116, dis->win_h / 2 - 42);
}

int		key_press(int keycode, void *param)
{
	t_display *dis;

	dis = (t_display *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
	{
		dis->pause = (dis->pause + 1) % 2;
		if (dis->pause)
			mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->pause_xpm,
					dis->win_l / 2 - 116, dis->win_h / 2 - 42);
		else
			refresh_screen(dis);
	}
	if (keycode == 34)
	{
		dis->info = (dis->info + 1) % 2;
		if (!dis->info)
			pause_no_info(dis);
		if (dis->info)
			print_info(dis);
	}
	if (keycode == 2)
		dis->disable_p = (dis->disable_p + 1) % 2;
	return (0);
}
