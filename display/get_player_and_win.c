/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_and_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:32:30 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/08 16:48:40 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"

void	get_player_and_map(t_display *dis)
{
	int		ret;
	char	*line;
	int		player;

	line = NULL;
	player = 1;
	ret = 0;
	while (1)
	{
		if ((ret = get_next_line(0, &line, 0)) == -1)
			free_and_end(dis);
		if (line && line[0] == '$')
			get_player_name(line, dis, player++);
		else if (line && ft_strstr(line, "Plateau"))
		{
			get_map_info(dis, line);
			calc_size_block(dis);
			free(line);
			break ;
		}
		if (ret)
			free(line);
	}
}

int		get_player_name(char *line, t_display *dis, int player)
{
	char	*buff;
	int		i;
	int		size;
	int		start;

	i = 0;
	size = 0;
	while (line[i] != '[')
		i++;
	buff = ft_strchr(line, '/');
	start = buff ? buff - (line + i) + 1 : 1;
	if (player == 1 && !(dis->name1 =
				ft_strsub(line + i, start, ft_strstr(line, ".filler")
					- (line + i) - start)))
		free_and_end(dis);
	if (player == 2 && !(dis->name2 =
				ft_strsub(line + i, start, ft_strstr(line, ".filler")
					- (line + i) - start)))
		free_and_end(dis);
	return (1);
}
