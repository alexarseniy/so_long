/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:38:12 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/12 23:08:29 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

static void	pj_init_start_point(t_game *game)
{
	int	i;
	int	j;

	if (!game || !game->map.map)
		exit(1);
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] && game->map.map[i][j] != 'P')
			j++;
		i++;
	}
	game->pj.pos_x = j;
	game->pj.pos_y = i;
}

void	init_pj(t_game *game)
{
	char_init_values(&(game->pj), PJ_PATH);
	if(char_init_movement_sprites(&(game->pj), game) != OK)
		exit(1);
	pj_init_start_point(game);
}
