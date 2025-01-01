/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:14 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/01 20:17:27 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Function: start_game
 * --------------------
 * @brief Giving a map, intialize the game properties and launch the game. If
 * the game closes, call the destruction functions to close all process and free
 * the memmory
 *
 * @param map 2 dimension char array that has the game's map to create.
 *
 * @return No return
 */
static void	start_game(t_game_interface *game_interface)
{
	//mlx_loop(game_interface->mlx);
	if (game_interface)
		return ;
	//TODO
	return ;
}

/*
 * Function: main
 * --------------
 * @brief Given the file name from where it has to read the map. Reads the map
 * check if it's a valid one. If error exists, then the program finish it's
 * execution. Otherwise, starts the game.
 *
 * Once the game is finished. Free print the played map and free it's memmory.
 *
 * @param argc Number of arguments. Has to be 2: Program name and file name
 * @param argv Arguments. First one the program name, then the map's file name.
 *
 * @return 0 if OK or error number if there is an error
 */
int	main(int argc, char **argv)
{
	t_game_interface	game_interface;

	if (argc != 2)
		return (print_error(ERROR_INVALID_NUMBER_ARGUMENTS));
	if (!is_valid_file_name(argv[1]))
		return (print_error(ERROR_INVALID_FILE_NAME));
	game_interface = init_game_interface(argv[1]);
	start_game(&game_interface);
	destroy_game_interface(game_interface);
	return (0);
}
