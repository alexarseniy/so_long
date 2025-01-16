/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:47:38 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 17:04:16 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_checker.h"

static char	**duplicate_map(char **map)
{
	char	**result;
	int		i;
	int		lines;

	lines = 0;
	while (map[lines])
		lines++;
	result = ft_calloc(lines + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (map[i])
	{
		result[i] = ft_strdup(map[i]);
		if (!result[i])
			return (free_map(&result), NULL);
		i++;
	}
	return (result);
}

static void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1' 
		|| map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static bool	has_start_or_exit(char **map)
{
	int	i;
	int	j;
	int	n_starts;
	int	n_ends;

	i = 0;
	n_starts = 0;
	n_ends = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				n_starts += 1;
			if (map[i][j] == 'E')
				n_ends += 1;
			j++;
		}
		i++;
	}
	if (n_starts == 1 || n_ends == 1)
		return (true);
	return (false);
}

bool has_valid_path(char **map)
{
	char	**map_copy;
	bool	valid_path;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	map_copy = duplicate_map(map);
	if (!map_copy)
		return (false);
	flood_fill(map_copy, j, i);
	valid_path = !(has_start_or_exit(map_copy) || has_collects(map_copy));
	return (free_map(&map_copy), valid_path);
}
