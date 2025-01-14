/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:36:44 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/13 00:56:56 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"
#include "read_map.h"
#include "mlx.h"

static void	map_init_values(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->map = NULL;
	map->wall_sprite = NULL;
	map->floor_sprite = NULL;
	map->exit_closed = NULL;
	map->exit_opened = NULL;
	map->is_exit_closed = true;
}

static void	set_map_size(t_map *map)
{
	int	i;

	if (!map || !map->map)
		return ;
	map->width = ft_strlen(map->map[0]);
	i = 0;
	while (map->map[i])
		i++;
	map->height = i;
}

void	init_map(t_game *game, char *map_file)
{
	int	sprite_size;

	if (!game)
		return ;
	sprite_size = 32;
	map_init_values(&(game->map));
	game->map.map= read_map(map_file);
	set_map_size(&(game->map));
	game->map.wall_sprite = mlx_xpm_file_to_image(game->mlx, WALL_SPRITE, 
			&sprite_size, &sprite_size);
	game->map.floor_sprite = mlx_xpm_file_to_image(game->mlx, FLOOR_SPRITE, 
			&sprite_size, &sprite_size);
	game->map.exit_closed = mlx_xpm_file_to_image(game->mlx, EXIT_CLOSED,
			&sprite_size, &sprite_size);
	game->map.exit_opened = mlx_xpm_file_to_image(game->mlx, EXIT_OPENED,
			&sprite_size, &sprite_size);
}
