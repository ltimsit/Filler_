/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:43:22 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/07/02 17:26:39 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdlib.h>
# define W_H 1200
# define W_L 1600
# define X_H 720
# define X_L 1280
# define P1 0x22FF55
# define P2 0xFF3333
# define HYP 0x999999
# define F_C 0xFF33E3
# define XPM_NB 5

typedef struct	s_display
{
	void		*mlx_ptr;
	void		*w_ptr;
	void		*img_ptr;
	char		*data_ptr;
	char		*xpm_name[XPM_NB];
	int			xpm_file_nb;
	char		**xpm_tab;
	void		*xpm_img;
	void		*pause_xpm;
	void		*fond_xpm;
	void		*powb_xpm;
	void		*ppause_xpm;
	int			b_size;
	int			win_h;
	int			win_l;
	int			map_h;
	int			map_l;
	int			s_p1;
	int			s_p2;
	int			p1_played;
	int			p2_played;
	char		score_p1[25];
	char		score_p2[25];
	int			hype1;
	int			hype2;
	char		*name1;
	char		*name2;
	char		*hype;
	int			finish;
	int			pause;
	int			disable_p;
	int			info;
	int			term;
}				t_display;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

void			init_data(t_display *dis, char *path, char *option);
int				ft_abs(int a);
void			print_info(t_display *dis);
void			fill_background(t_display *dis);
int				key_press(int keycode, void *param);
char			*ft_itoa_score(int n, char *str);
int				get_player_name(char *line, t_display *dis, int player);
void			get_player_and_map(t_display *dis);
void			get_map_info(t_display *dis, char *line);
void			calc_size_block(t_display *dis);
int				close_x(void *param);
void			free_and_end(t_display *dis);
void			free_and_exit_xpm(char **xpm, int i, char *path_xpm);
int				pause_screen(t_display *dis);
void			hype(int p1, int p2, t_display *dis);
void			fill_data(char *line, char *data, t_display *dis, int *cpt);
#endif
