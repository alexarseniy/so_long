/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:59:35 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 13:18:18 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

static void	clean_sprites_mem(t_game *game)
{
	game->sprites.wall = NULL;
	game->sprites.floor = NULL;
	game->sprites.exit_closed = NULL;
	game->sprites.exit_opened = NULL;
	game->sprites.collect = NULL;
	game->sprites.pj = NULL;
	game->sprites.npc = NULL;
}

void	destroy_sprites(t_game *game)
{
	int	i;

	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
	if (game->sprites.exit_closed)
		mlx_destroy_image(game->mlx, game->sprites.exit_closed);
	if (game->sprites.exit_opened)
		mlx_destroy_image(game->mlx, game->sprites.exit_opened);
	if (game->sprites.collect)
		mlx_destroy_image(game->mlx, game->sprites.collect);
	i = 0;
	while (i < N_CHAR_SPRITES + 1)
	{
		if (game->sprites.pj)
			mlx_destroy_image(game->mlx, game->sprites.pj[i]);
		if (game->sprites.npc)
			mlx_destroy_image(game->mlx, game->sprites.npc[i]);
		i++;
	}
	free(game->sprites.pj);
	free(game->sprites.npc);
	clean_sprites_mem(game);
}
