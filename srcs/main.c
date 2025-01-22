/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:58:57 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/22 22:37:42 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static int	key_press(int key, t_game *game)
{
	if (key == 0xff1b || key == XK_Q || key == XK_q)
		exit_game(EXIT_KEY, game);
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
	render(game);
	check_pj_npc_collision(game);
	return (0);
}

static int	exit_click(t_game *game)
{
	exit_game(EXIT_KEY, game);
	return (0);
}

static void	start_game(t_game *game)
{
	mlx_key_hook(game->window, key_press, game);
	mlx_hook(game->window, 17, 0, exit_click, game);
	render(game);
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
	return (0);
}
