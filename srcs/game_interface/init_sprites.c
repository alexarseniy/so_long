/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:07:06 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 13:22:24 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	sprites_init_values(t_sprites *sprites)
{
	sprites->width = IMG_WIDTH;
	sprites->height = IMG_HEIGHT;
	sprites->wall = NULL;
	sprites->floor = NULL;
	sprites->exit_closed = NULL;
	sprites->exit_opened = NULL;
	sprites->collect = NULL;
	sprites->pj = NULL;
	sprites->npc = NULL;
}

static char *generate_pj_path(char *path, int tile_n)
{
	char	*sprite_num;
	char	*path_with_n;
	char	*path_with_extension;

	sprite_num = ft_itoa(tile_n);
	if (!sprite_num)
		return (NULL);
	path_with_n = ft_strjoin(path, sprite_num);
	if (!path_with_n)
		return (free(sprite_num), NULL);
	path_with_extension = ft_strjoin(path_with_n, SPRITE_EXTENSION);
	return (free(sprite_num), free(path_with_n), path_with_extension);
}

static void	**load_char_sprites(t_game *game, char *path)
{
	void	**sprites;
	char	*full_path;
	int		i;

	sprites = ft_calloc(N_CHAR_SPRITES + 1, sizeof(void *));
	if (!sprites)
		return (NULL);
	i = 0;
	while (i < N_CHAR_SPRITES + 1)
	{
		full_path = generate_pj_path(path, i);
		if (!full_path)
			return (free(sprites), NULL);
		sprites[i] = mlx_xpm_file_to_image(game->mlx, full_path,
				&(game->sprites.width), &(game->sprites.height));
		if (!sprites[i])
			return (free(sprites), free(full_path), NULL);
		free(full_path);
		i++;
	}
	return (sprites);
}

static void	check_sprites_loaded(t_game *game)
{
	t_sprites sprites;

	sprites = game->sprites;
	if (!sprites.wall || !sprites.floor || !sprites.exit_closed ||
		!sprites.exit_opened || !sprites.collect || !sprites.pj ||
		!sprites.npc)
		exit_error(ERROR_LOADING_SPRITES, game);
}

void	init_sprites(t_game *game)
{
	sprites_init_values(&(game->sprites));
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE,
			&(game->sprites.width), &(game->sprites.height));
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE,
			&(game->sprites.width), &(game->sprites.height));
	game->sprites.exit_closed = mlx_xpm_file_to_image(game->mlx, EXIT_CLOSED,
			&(game->sprites.width), &(game->sprites.height));
	game->sprites.exit_opened = mlx_xpm_file_to_image(game->mlx, EXIT_OPENED,
			&(game->sprites.width), &(game->sprites.height));
	game->sprites.collect = mlx_xpm_file_to_image(game->mlx, COLLECT_PATH,
			&(game->sprites.width), &(game->sprites.height));
	game->sprites.pj = load_char_sprites(game, PJ_PATH);
	game->sprites.npc = load_char_sprites(game, NPC_PATH);
	check_sprites_loaded(game);
}
