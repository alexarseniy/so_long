/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:14 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/28 19:03:03 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map_checker.h"

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
static void	start_game(char **map)
{
	void	*mlx;
	//void	*window;

	mlx = mlx_init();
	//window = mlx_new_window(mlx, 300, 200, "Mi ventana ;)");
	//mlx_loop(mlx);
	map = NULL;
	//mlx_destroy_window(mlx, window);
	free(mlx);
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
	char	**map;
	t_error	error;

	if (argc != 2)
		return (print_error(ERROR_INVALID_NUMBER_ARGUMENTS));
	if (!is_valid_file_name(argv[1]))
		return (print_error(ERROR_INVALID_FILE_NAME));
	map = read_map(argv[1]);
	error = check_valid_map(map);
	if (error)
	{
		free_map(map);
		return (error);
	}
	start_game(map);
	free_map(map);
	return (0);
}
