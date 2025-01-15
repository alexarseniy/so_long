/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game_interface.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:51:20 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 17:47:51 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	destroy_game_interface(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	destroy_map(game);
	destroy_collectables(game);
	destroy_npcs(game);
	destroy_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	game->window = NULL;
}
