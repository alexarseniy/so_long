/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:36:44 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/22 01:56:00 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"
#include "read_map.h"

void	map_init_values(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map = NULL;
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
	t_error	error;

	if (!is_valid_map_file(map_file))
		exit_error(ERROR_INVALID_MAP_FILE_NAME, game);
	game->map.map = read_map(map_file);
	if (!game->map.map)
		exit_error(ERROR_READ_MAP, game);
	set_map_size(&(game->map));
	if (game->map.width * game->map.height > MAX_MAP_SIZE)
		exit_error(ERROR_MAP_SIZE, game);
	error = is_valid_map(game->map.map);
	if (error != OK)
		exit_error(error, game);
}
