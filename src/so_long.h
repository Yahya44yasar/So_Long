/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:06:46 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/07 16:47:22 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdbool.h>
# include <fcntl.h>
# include <time.h>

typedef struct s_img
{
	void	*back;
	void	*loot;
	void	*player;
	void	*door;
	void	*wall;
	void	*title;
}t_img;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		a;
	int		enemy_anm_c;
	int		enemy_x;
	int		enemy_y;
	int		val;
	int		map_x;
	int		map_y;
	int		player_x;
	int		player_y;
	int		coin;
	int		player;
	int		exit;
	int		ch_coin;
	int		ch_exit;
	int		move;
	char	**map;
	t_img	*img;
}t_data;

void	error(char *str);
void	check_format(char *mapname, t_data *data);
void	pce10_control(t_data *g);
void	wall_control(t_data *data);
void	rectangel_control(t_data *data);
void	control_map(t_data *data);
void	char_control(t_data *g);
void	valid_path(t_data *a);
void	map_edit(t_data *g);
void	err_map(t_data *g, int x, int y);
void	coin_check(t_data *g, int x, int y);
void	exit_check(t_data *err, int x, int y);
char	*get_next_line(int fd);
void	*myfree(void *str);
void	map_init(t_data *data, char *arg1);
int		find_max_y(char *s, t_data *data);
void	up(t_data *g);
void	down(t_data *g);
void	left(t_data *g);
void	right(t_data *g);
int		redraw_map(t_data *g);
int		exit_hook(t_data *game);
int		key_func(int code, t_data *g);
void	create_mlx(t_data *g);
void	draw_img(t_data *g);
void	draw_img_ul(t_data *g, int x, int y);
void	put_img(t_data *g);
#endif