/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_interface.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:33:04 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/12 21:33:24 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"
#include "error_checker.h"
#include "mlx.h"

static void	game_interface_init_values(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->npcs = NULL;
	game->collectables = NULL;
}

static void	init_game_structs(t_game *game, char *map_file)
{
	init_map(game, map_file);
	init_pj(game);
	init_npcs(game);
	//init_counter(&(game->counter));
	//init_collectable(&(game->collectables));
}

void	init_game_interface(t_game *game, char *map_file)
{
	if (!game)
		return ;
	game_interface_init_values(game);
	game->mlx = mlx_init();
	init_game_structs(game, map_file);
	game->window = mlx_new_window(game->mlx, game->map.width * IMG_WIDTH,
			game->map.height * IMG_HEIGHT, "so_long");
}
