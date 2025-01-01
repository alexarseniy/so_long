/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:39:45 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/01 19:56:27 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKER_H
# define MAP_CHECKER_H

# include <stdbool.h>
# define VALID_MAP_CHARS "01PEC"

typedef enum e_error
{
	OK = 0,
	ERROR,
	ERROR_MAP_NOT_RECTANGLE,
	ERROR_MAP_HAS_INVALID_CHAR,
	ERROR_NOT_ROUNDED_BY_WALLS,
	ERROR_NUMBER_OF_INIT_EXIT_CHARS,
	ERROR_NOT_COLLECTABLES_FOUND,
	ERROR_NOT_VALID_PATH,
	ERROR_INVALID_NUMBER_ARGUMENTS,
	ERROR_INVALID_FILE_NAME,
	ERROR_MAP,
	ERROR_INIT_MAP,
	ERROR_INIT_MLX,
	ERROR_INIT_MLX_WINDOW
}	t_error;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

t_error	check_valid_map(char **map);
bool	is_valid_sqare_map(char **map);
bool	has_valid_chars(char **map);
bool	is_rounded_by_walls(char **map);
bool	has_one_init_exit(char **map);
bool	has_min_one_c(char **map);
char	**strs_copy(char **strs);
t_point	find_start_point(char **map);
void	flood_fill_recursive(char **map, t_point map_size, t_point start_point);
void	flood_fill(char **map);
bool	has_valid_path(char **map);
bool	has_one_exit(char **map);
bool	is_valid_file_name(char *file_name);
t_error	print_error(t_error error);

#endif
