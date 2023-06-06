/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:00:09 by yyasar            #+#    #+#             */
/*   Updated: 2023/06/04 13:42:13 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arg, char	**argv)
{
	t_data	data;

	if (arg != 2)
		write(1, "arguman error", 14);
	map_control(argv, &data);
	size_control(&data);
	mlx_create(&data);
}
