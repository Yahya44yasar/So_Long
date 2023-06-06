/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:15:24 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 11:01:29 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_control(char *mapname, t_data *data)
{
	int	i;

	i = ft_strlen(mapname[1]);
	if (mapname[i - 1] != 'r' || mapname[i - 2] != 'e'
		|| mapname[i - 3] != 'b' || mapname[i - 4] != '.')
		error(".ber error");
}

void	tmp_control(char *mapname, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(ft_strjoin("map/", mapname), O_RDONLY);
	if (fd == -1)
		error("map not found");
	line = get_next_line(fd);
	if (!*line)
		error("map is empty");
	close(fd);
	free(line);
	if (!mapname)
		free(mapname);
}

void	map_control(char **argv, t_data *data)
{
	char	*map_name;
	char	*map_name_ber;

	if (argv[1] == 0)
		error("no map file");
	map_name = argv[1];
	map_name_ber = ft_strjoin("map/", map_name);
	data->map_tmp = map_name_ber;
	free(map_name_ber);
	ber_control(argv[1], data);
	tmp_control(argv[1], data);
}

