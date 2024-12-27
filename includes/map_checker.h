/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:39:45 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/27 22:21:36 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKER_H
# define MAP_CHECKER_H

# include <stdbool.h>
# define VALID_MAP_CHARS "01PE"

typedef enum e_error
{
	OK = 0,
	ERROR
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
bool	has_min_one_C(char **map);
char	**strs_copy(char **strs);
t_point	find_start_point(char **map);
void	flood_fill_recursive(char **map, t_point map_size, t_point start_point);
void	flood_fill(char **map);
bool	has_valid_path(char **map);
bool	has_one_exit(char **map);

#endif
