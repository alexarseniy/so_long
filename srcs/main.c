/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:58:57 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 18:07:54 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				image = game->sprites.wall;
			else if (game->map.map[i][j] == '0')
				image = game->sprites.floor;
			else if (game->map.map[i][j] == 'P')
				image = game->sprites.pj[0];
			else if (game->map.map[i][j] == 'N')
				image = game->sprites.npc[1];
			else if (game->map.map[i][j] == 'E' && game->map.is_exit_closed)
				image = game->sprites.exit_closed;
			else if (game->map.map[i][j] == 'E' && !game->map.is_exit_closed)
				image = game->sprites.exit_opened;
			else if (game->map.map[i][j] == 'C')
				image = game->sprites.collect;
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
		return (exit_error(ERROR_N_ARGS));
	init_game_interface(&game, argv[1]);
	render(&game);
	print_map(game.map.map);
	destroy_game_interface(&game);
	return (0);
}
