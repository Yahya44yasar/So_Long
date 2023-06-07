/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:51:46 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/07 16:43:40 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_max_y(char *s, t_data *data)
{
	char	*a;
	int		i;
	int		fd;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		error("arguman 1 not fount (fd)");
	a = get_next_line(fd);
	while (a && *s)
	{
		i++;
		free(a);
		a = get_next_line(fd);
	}
	return (i);
}

void	map_init(t_data *data, char *arg1)
{
	char	*s;
	int		i;
	int		fd;

	i = 0;
	data->map_y = find_max_y(arg1, data);
	fd = open(arg1, O_RDONLY);
	data->map = malloc(sizeof(char *) * data->map_y);
	if (fd == -1 || !data->map || data->map_y < 3)
		error(" error on map_init");
	s = get_next_line(fd);
	while (i < data->map_y)
	{
		data->map[i] = s;
		i++;
		s = get_next_line(fd);
	}
	close(fd);
}

int	key_func(int code, t_data *g)
{
	if (code == 13 || code == 1 || code == 0 || code == 2)
	{
		if (code == 0)
			left(g);
		if (code == 2)
			right(g);
		if (code == 13)
			up(g);
		if (code == 1)
			down(g);
		ft_printf("\rMovement Counter : %i", g->move);
	}
	if (code == 53 || code == 12)
	{
		free(g);
		mlx_destroy_window(g->mlx, g->window);
		exit(0);
	}
	return (0);
}

int	exit_hook(t_data *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free(game);
	exit(0);
}
