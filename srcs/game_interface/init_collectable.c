/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:42:03 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/20 01:53:51 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

static int	count_collects(char **map)
{
	int	i;
	int	j;
	int	result;

	result = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

static void	collect_init_position(char **map, t_collectable *collect)
{
	static int	x = 0;
	static int	y = 0;
	int			start_x;
	int			start_y;

	start_x = x;
	start_y = y;
	while (map[y])
	{
		if (!map[y][x] || map[y][x] == '1')
			x = 0;
		while ((map[y][x] && map[y][x] != 'C') ||
			(x == start_x && y == start_y))
			x++;
		if (map[y][x] == 'C')
			break ;
		y++;
	}
	collect->pos_x = x;
	collect->pos_y = y;
}

void	init_collectable(t_game *game)
{
	t_collectable	*collects;
	int				n_collects;
	int				i;

	n_collects = count_collects(game->map.map);
	collects = ft_calloc(n_collects, sizeof(t_collectable *));
	if (!collects)
		exit_error(ERROR_MALLOC_COLLECTS, game);
	i = 0;
	while (i < n_collects)
	{
		collect_init_position(game->map.map, &(collects[i]));
		collects[i].is_collected = false;
		i++;
	}
	game->collectables = collects;
	game->n_collects = n_collects;
}
