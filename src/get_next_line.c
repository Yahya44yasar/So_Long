/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:03:50 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 16:14:52 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	char	buffer;
	int		rd_byt;

	line = (char *)malloc(sizeof(char) * 4444);
	rd_byt = 1;
	i = 0;
	while (rd_byt > 0)
	{
		rd_byt = read(fd, &buffer, 1);
		if (rd_byt <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;

	}
	line[i] = '\0';
	if (!*line)
		free(line);
	return (line);
}
/*
int	main(void)
{
	int		fd;

	fd = open("../map/map1.ber", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/