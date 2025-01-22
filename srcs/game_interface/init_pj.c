/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:38:12 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 21:24:36 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

static void	pj_init_start_point(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] && game->map.map[i][j] != 'P')
			j++;
		if (game->map.map[i][j] == 'P')
			break ;
		i++;
	}
	game->pj.x = j;
	game->pj.y = i;
}

void	init_pj(t_game *game)
{
	pj_init_start_point(game);
	game->pj.direction = 0;
}
