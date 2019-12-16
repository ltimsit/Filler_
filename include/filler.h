/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:48:20 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/08 18:52:45 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_data
{
	int			**map;
	char		**piece;
	int			line_nb;
	int			b_line_nb;
	int			number;
	char		*name;
	int			length;
	int			height;
	int			b_length;
	int			b_height;
	char		symbole;
	char		en_symb;
	int			display_bool;
}				t_data;

typedef	struct	s_coord
{
	int			x;
	int			y;
	int			finish;
	int			filled;
}				t_coord;

typedef struct	s_display
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_ptr;
	int			color_p1;
	int			color_p2;
	char		*name_p1;
	char		*name_p2;
	int			height;
	int			length;
}				t_display;

typedef struct	s_couple
{
	t_data		*data;
	t_display	*dis;
	t_coord		*result;
}				t_couple;

int				get_player_info(char *line, t_data *data);
int				get_line(t_data *data, char **line);
int				check_data(t_data *data);
void			init_data_result(t_data *data, t_coord *result);
int				get_map_info(char *line, t_data *data);
int				get_piece_info(char *line, t_data *data);
int				**fill_map(char **line, t_data *data);
char			**fill_piece(char **line, t_data *data);
char			**create_piece(t_data *data);
int				**create_map(t_data *data);
void			**free_all(void **data, int i);
void			calc_result(t_data *data);
int				parse(t_data *data);
void			test_pos_block(t_data *data, t_coord *coord);
void			fill_rest_map(t_data *data, t_coord *coord);
void			init_display(t_data *data, t_display *d);
int				display(t_data *data, t_display *d);
void			init_coord(t_coord *coord);
int				ft_abs(int nb);
int				free_l(char *line);
int				player_error(t_data *data, char *line);
int				map_error(t_data *data, int type, char *line);
int				piece_error(t_data *data, int type, char *line);
int				read_error(t_data *data, char *line, int option);

#endif
