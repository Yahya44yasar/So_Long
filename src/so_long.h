/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:00:52 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 18:13:07 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define IMG_SIZE 50 //resim boyutu

typedef struct l_image
{
	char	*adem;
	char	*salih;
	char	*yahya;
	char	*taxi;
	char	*door;
	char	*door_open;
	char	*wire;
	char	*bg;
	int		img_w;
	int		img_h;
}	t_image;

typedef struct l_int_map
{
	int	l;
	int	r;
	int	t;
	int	b;
	int	read_count;
	int	step_count;
}		t_int_map;

typedef struct l_data
{
	char		**map;
	char		*mlx;
	char		*win;
	char		*map_tmp;
	int			map_height;
	int			map_width;
	int			player_count;
	int			exit_count;
	int			wall_count;
	int			coin_count;
	int			step_count;
	int			coin_collected;
	int			unwanted_character_count;
	int			exit_x;
	int			exit_y;
	int			player_x;
	int			player_y;

	t_image		img;
	t_int_map	i_map;
}	t_data;

void	error(char	*str);
void	map_control(char **argv, t_data *data);
void	tmp_control(char *mapname, t_data *data);
void	ber_control(char *mapname, t_data *data);
char	*get_next_line(int fd);
void	size_control(t_data *data);
void	wall_control(t_data *data);
void	min_eleman_control(t_data *data);
void	mlx_create(t_data *data);
void	map_read(t_data *data);
void	map_bacgraunt_put(t_data *data);
void	map_create(t_data *data);
void	map_put(int i, int j, t_data *data);
void	placeholder(t_data *data, int x, int y);
#endif