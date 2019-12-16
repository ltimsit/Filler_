/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:47:35 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/02 13:55:42 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"

void	print_info(t_display *dis)
{
	mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->xpm_img, 0, 0);
	mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->fond_xpm,
			dis->win_l - 300, 0);
	mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr, dis->powb_xpm, 10,
			dis->win_h - 50);
	mlx_string_put(dis->mlx_ptr, dis->w_ptr, dis->win_l - 200, 30, P1,
			dis->name1);
	mlx_string_put(dis->mlx_ptr, dis->w_ptr, dis->win_l - 200, 50, P1,
			dis->score_p1);
	mlx_string_put(dis->mlx_ptr, dis->w_ptr, dis->win_l - 200, 80, P2,
			dis->name2);
	mlx_string_put(dis->mlx_ptr, dis->w_ptr, dis->win_l - 200, 100, P2,
			dis->score_p2);
}

void	fill_background(t_display *dis)
{
	int x;
	int y;

	y = 0;
	while (y < dis->win_h)
	{
		x = 0;
		while (x < dis->win_l)
		{
			mlx_put_image_to_window(dis->mlx_ptr, dis->w_ptr,
					dis->ppause_xpm, x, y);
			x += X_L;
		}
		y += X_H;
	}
}
