/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:43:06 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/28 02:46:42 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"
#include "libft.h"
#include "parse_map.h"
#include <stdbool.h>

bool	is_valid_sqare_map(char **map)
{
	int	i;
	int	row_len;
	int	first_row_len;

	i = 0;
	if (map[i])
		first_row_len = ft_strlen(map[i]);
	while (map[i])
	{
		row_len = ft_strlen(map[i]);
		if (row_len != first_row_len)
			return (false);
		i++;
	}
	return (true);
}

bool	has_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(VALID_MAP_CHARS, map[i][j]) && map[i][j] != '\n')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_rounded_by_walls(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || map[i + 1] == NULL) && map[i][j] != '1')
				return (false);
			if (i != 0 && map[i + 1] != NULL && map[i][j] != '1' && (j == 0 ||
				j == ft_strlen(map[i]) - 1))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	has_one_init_exit(char **map)
{
	int	i;
	int	j;
	int	n_start_point;
	int	n_exit_point;

	i = 0;
	n_start_point = 0;
	n_exit_point = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				n_start_point++;
			if (map[i][j] == 'E')
				n_exit_point++;
			j++;
		}
		i++;
	}
	if (n_start_point != 1 || n_exit_point != 1)
		return (false);
	return (true);
}

t_error	check_valid_map(char **map)
{
	t_error	error;

	if (!map || !*map)
		error = ERROR_MAP;
	else if (!is_valid_sqare_map(map))
		error = ERROR_MAP_NOT_RECTANGLE;
	else if (!has_valid_chars(map))
		error = ERROR_MAP_HAS_INVALID_CHAR;
	else if (!is_rounded_by_walls(map))
		error = ERROR_NOT_ROUNDED_BY_WALLS;
	else if (!has_one_init_exit(map))
		error = ERROR_NUMBER_OF_INIT_EXIT_CHARS;
	else if (!has_min_one_c(map))
		error = ERROR_NOT_COLLECTABLES_FOUND;
	else if (!has_valid_path(map))
		error = ERROR_NOT_VALID_PATH;
	else
		error = OK;
	return (print_error(error));
}
