/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:41:00 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/22 21:53:54 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CHECKER_H
# define ERROR_CHECKER_H

# include "libft.h"
# include "game_interface.h"
# include <stdbool.h>

# ifndef VALID_CHARS
#  define VALID_CHARS "01CPE"
# endif
# define MAX_MAP_SIZE	1000

typedef struct s_game	t_game;

typedef enum e_error
{
	OK = 0,
	ERROR_N_ARGS,
	ERROR_INIT_GAME_INTERFACE,
	ERROR_INIT_MLX,
	ERROR_INIT_MLX_WINDOW,
	ERROR_INVALID_MAP_FILE_NAME,
	ERROR_READ_MAP,
	ERROR_MAP_SIZE,
	ERROR_NO_RECTANGLE,
	ERROR_INVALID_CHARS,
	ERROR_MAP_NOT_ROUNDED_WALLS,
	ERROR_N_START_EXIT,
	ERROR_NO_COLLECTS,
	ERROR_MAP_PATH,
	ERROR_MALLOC_NPCS,
	ERROR_MALLOC_COLLECTS,
	ERROR_LOADING_SPRITES,
	ERROR_SETTING_N_STEPS_COLLECTS,
	ERROR_SETTING_S_STEPS_COLLECTS,
	ERROR
}	t_error;

t_error	is_valid_map(char **map);
void	print_error(t_error err);
void	exit_error(t_error err, t_game *game);
bool	is_rectangle_map(char **map);
bool	is_rounded_walls(char **map);
bool	has_one_start_exit(char **map);
bool	has_collects(char **map);
bool	has_valid_path(char **map);
bool	has_valid_chars(char **map);
bool	is_valid_map_file(char *map_file);

#endif
