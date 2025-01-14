/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:58:57 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/13 01:04:06 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_utils.h"
#include "so_long.h"

static void	render(t_game *game)
{
	int	i;
	int	j;
	void *image;

	if (!game || !game->map.map)
		exit(1);
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				image = game->map.wall_sprite;
			else if (game->map.map[i][j] == '0')
				image = game->map.floor_sprite;
			else if (game->map.map[i][j] == 'P')
				image = game->pj.movement_sprites[0];
			else if (game->map.map[i][j] == 'N')
				image = game->npcs[0].movement_sprites[1];
			else if (game->map.map[i][j] == 'E' && game->map.is_exit_closed)
				image = game->map.exit_closed;
			else if (game->map.map[i][j] == 'E' && !game->map.is_exit_closed)
				image = game->map.exit_opened;
			mlx_put_image_to_window(game->mlx, game->window, image, j * 32,
					i * 32);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	init_game_interface(&game, argv[1]);
	render(&game);
	print_map(game.map.map);
	free_map(&(game.map.map));
	return (0);
}
