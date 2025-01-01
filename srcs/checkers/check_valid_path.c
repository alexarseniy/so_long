/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:24:37 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/01 20:01:19 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"
#include "libft.h"
#include <stdbool.h>
#include "read_map.h"

char	**strs_copy(char **strs)
{
	char	**result;
	int		i;

	if (!strs)
		return (NULL);
	i = 0;
	while (strs[i])
		i++;
	result = ft_calloc(i + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		result[i] = ft_strdup(strs[i]);
		if (!result[i])
		{
			free_map(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

t_point	find_start_point(char **map)
{
	t_point	start_point;
	bool	point_found;

	start_point.y = 0;
	start_point.x = 0;
	point_found = false;
	while (map[start_point.y] && !point_found)
	{
		start_point.x = 0;
		while (map[start_point.y][start_point.x] && !point_found)
		{
			if (map[start_point.y][start_point.x] == 'P')
				point_found = true;
			else
				start_point.x++;
		}
		if (point_found)
			break ;
		start_point.y++;
	}
	return (start_point);
}

void	flood_fill_recursive(char **map, t_point map_size, t_point start_point)
{
	if (start_point.x > map_size.x || start_point.x <= 0)
		return ;
	if (start_point.y > map_size.y || start_point.y <= 0)
		return ;
	if (map[start_point.y][start_point.x] == '1')
		return ;
	if (map[start_point.y][start_point.x] == 'F')
		return ;
	map[start_point.y][start_point.x] = 'F';
	start_point.y += 1;
	flood_fill_recursive(map, map_size, start_point);
	start_point.y -= 2;
	flood_fill_recursive(map, map_size, start_point);
	start_point.y += 1;
	start_point.x += 1;
	flood_fill_recursive(map, map_size, start_point);
	start_point.x -= 2;
	flood_fill_recursive(map, map_size, start_point);
	start_point.x += 1;
}

void	flood_fill(char **map)
{
	t_point	start_point;
	t_point	map_size;

	start_point = find_start_point(map);
	if (start_point.x == 0 && start_point.y == 0)
		return ;
	map_size.x = 0;
	map_size.y = 0;
	while (map[map_size.y])
		map_size.y++;
	while (map[0][map_size.x])
		map_size.x++;
	flood_fill_recursive(map, map_size, start_point);
}

bool	has_valid_path(char **map)
{
	char	**map_copy;
	bool	is_valid;

	map_copy = strs_copy(map);
	if (!map_copy)
		return (false);
	flood_fill(map_copy);
	if (has_one_exit(map_copy) || has_min_one_c(map_copy))
		is_valid = false;
	else
		is_valid = true;
	free_map(map_copy);
	return (is_valid);
}
