/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:49:06 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/22 22:33:24 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_wall_collision(t_char charac, char **map, int x, int y)
{
	if (map[charac.y + y][charac.x + x] == '1')
		return (true);
	return (false);
}

bool	check_npc_collision(t_char charac, char **map, int x, int y)
{
	if (map[charac.y + y][charac.x + x] == 'N')
		return (true);
	return (false);
}

static bool	check_collision(t_char pj, t_char npc)
{
	bool	collision;

	collision = false;
	if (pj.y == npc.y && npc.x == pj.x + 1)
		collision = (pj.direction == LEFT && npc.direction == RIGHT);
	if (pj.y == npc.y && npc.x == pj.x - 1)
		collision = (pj.direction == RIGHT && npc.direction == LEFT);
	if (pj.x == npc.x && npc.y == pj.y + 1)
		collision = (pj.direction == UP && npc.direction == DOWN);
	if (pj.x == npc.x && npc.y == pj.y - 1)
		collision = (pj.direction == DOWN && npc.direction == UP);
	return (collision);
}

void	check_pj_npc_collision(t_game *game)
{
	int		i;
	t_char	pj;
	t_char	*npcs;

	i = 0;
	pj = game->pj;
	npcs = game->npcs;
	while (i < game->n_npcs && (npcs[i].x != pj.x || npcs[i].y != pj.y))
	{
		if (check_collision(pj, npcs[i]))
			exit_game(LOOSE, game);
		i++;
	}
	if (i < game->n_npcs)
		exit_game(LOOSE, game);
}
