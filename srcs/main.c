/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:58:57 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 17:47:56 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static void	render(t_game *game)
{
	int	i;
	int	j;
	void *image;

	if (!game || !game->map.map)
		exit_error(ERROR, game);
	mlx_clear_window(game->mlx, game->window);
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
			else if (game->map.map[i][j] == 'E' && game->exit.is_exit_closed)
				image = game->sprites.exit_closed;
			else if (game->map.map[i][j] == 'E' && !game->exit.is_exit_closed)
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

static int	key_press(int key, t_game *game)
{
	if (key == 0xff1b || key == XK_Q || key == XK_q)
		exit_error(ERROR, game);
	else if (key == XK_Up || key == XK_W || key == XK_w)
		pj_move(game, 0, -1, UP);
	else if (key == XK_Down || key == XK_S || key == XK_s)
		pj_move(game, 0, 1, DOWN);
	else if (key == XK_Left || key == XK_A || key == XK_a)
		pj_move(game, -1, 0, LEFT);
	else if (key == XK_Right || key == XK_D || key == XK_d)
		pj_move(game, 1, 0, RIGHT);
	else
		return (0);
	npcs_move(game);
	check_pj_npc_collision(game);
	update_map(game);
	render(game);
	return (0);
}


static void	start_game(t_game *game)
{
	render(game);
	mlx_key_hook(game->window, key_press, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ERROR_N_ARGS, NULL);
	srand(time(NULL));
	init_game_interface(&game, argv[1]);
	start_game(&game);
	print_map(game.map.map);
	destroy_game_interface(&game);
	return (0);
}
