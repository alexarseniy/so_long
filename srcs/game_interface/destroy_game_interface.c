/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game_interface.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:51:20 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 20:24:36 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	destroy_game_interface(t_game *game)
{
	if (game->mlx && game->window)
		mlx_clear_window(game->mlx, game->window);
	destroy_map(game);
	destroy_collectables(game);
	destroy_npcs(game);
	destroy_sprites(game);
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	game->window = NULL;
}
