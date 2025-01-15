/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:36:44 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 18:48:07 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"
#include "read_map.h"

void	map_init_values(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	map->is_exit_closed = true;
}

static void	set_map_size(t_map *map)
{
	int	i;

	map->width = ft_strlen(map->map[0]);
	i = 0;
	while (map->map[i])
		i++;
	map->height = i;
}

void	init_map(t_game *game, char *map_file)
{
	int	sprite_size;

	sprite_size = 32;
	game->map.map = read_map(map_file);
	if (!game->map.map)
		exit_error(ERROR_READ_MAP);
	set_map_size(&(game->map));
	check_map_errors(game->map.map);
}
