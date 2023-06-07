/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:41:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/07 15:08:30 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_control(t_data *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map_y)
	{
		j = 0;
		while (j < g->map_x)
		{
			if (g->map[i][j] == 'P')
			{
				g->player_x = j;
				g->player_y = i;
				g->player++;
			}
			if (g->map[i][j] == 'C')
				g->coin++;
			if (g->map[i][j] == 'E')
				g->exit++;
			j++;
		}
		i++;
	}
	if (g->player != 1 || g->coin < 1 || g->exit < 1)
		error("character count error");
}

void	*myfree(void *str)
{
	free (str);
	return (0);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		rd_byte;
	int		i;

	rd_byte = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 5700);
	buffer = 0;
	if (fd < 0)
		return (0);
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
		myfree(line);
	return (line);
}
