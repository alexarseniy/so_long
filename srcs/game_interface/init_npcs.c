/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_npcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:39:27 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/20 01:32:43 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

static int	count_npcs(char **map)
{
	int	n_npcs;
	int	i;
	int	j;

	i = 0;
	n_npcs = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				n_npcs++;
			j++;
		}
		i++;
	}
	return (n_npcs);
}

static void	npcs_init_start_point(char **map, t_char *npc)
{
	static int	x = 0;
	static int	y = 0;
	int			start_x;
	int			start_y;

	start_x = x;
	start_y = y;
	while (map[y])
	{
		if (map[y][x] == '1' || !map[y][x])
			x = 0;
		while ((map[y][x] && map[y][x] != 'N')
			|| (x == start_x && y == start_y))
			x++;
		if (map[y][x] == 'N')
			break ;
		y++;
	}
	npc->pos_x = x;
	npc->pos_y = y;
}

void	init_npcs(t_game *game)
{
	t_char	*npcs;
	int		n_npcs;
	int		i;

	n_npcs = count_npcs(game->map.map);
	npcs = ft_calloc(n_npcs, sizeof(t_char *));
	if (!npcs)
		exit_error(ERROR_MALLOC_NPCS, game);
	i = 0;
	while (i < n_npcs)
	{
		npcs_init_start_point(game->map.map, &(npcs[i]));
		i++;
	}
	game->npcs = npcs;
	game->n_npcs = n_npcs;
}
