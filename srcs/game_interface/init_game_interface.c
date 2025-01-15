/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_interface.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:33:04 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 18:47:29 by olarseni         ###   ########.fr       */
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
	map_init_values(&(game->map));
	char_init_values(&(game->pj));
	sprites_init_values(&(game->sprites));
	//counter_init_values(&(game->counter));
}

static void	init_game_structs(t_game *game, char *map_file)
{
	init_map(game, map_file);
	init_pj(game);
	init_npcs(game);
	//init_counter(&(game->counter));
	init_collectable(game);
	init_sprites(game);
}

void	init_game_interface(t_game *game, char *map_file)
{
	if (!game || !map_file)
		exit_error(ERROR_INIT_GAME_INTERFACE);
	game_interface_init_values(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(ERROR_INIT_MLX);
	init_game_structs(game, map_file);
	game->window = mlx_new_window(game->mlx, game->map.width * IMG_WIDTH,
			game->map.height * IMG_HEIGHT, "so_long");
	if (!game->window)
		exit_error(ERROR_INIT_MLX_WINDOW);
}
