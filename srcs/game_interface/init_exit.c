/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:10:03 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/19 23:18:01 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	init_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] && game->map.map[i][j] != 'E')
			j++;
		if (game->map.map[i][j] == 'E')
			break ;
		i++;
	}
	game->exit.pos_x = j;
	game->exit.pos_y = i;
	game->exit.is_exit_closed = true;
}
