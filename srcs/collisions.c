/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:49:06 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 23:51:11 by olarseni         ###   ########.fr       */
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

void	check_pj_npc_collision(t_game *game)
{
	int		i;
	t_char	pj;
	t_char	*npcs;
	bool	collision;

	i = 0;
	pj = game->pj;
	npcs = game->npcs;
	collision = false;
	while (i < game->n_npcs && (npcs[i].x != pj.x || npcs[i].y != pj.y))
	{
		if (pj.y == npcs[i].y && (npcs[i].x == pj.x + 1
				|| npcs[i].x == pj.x - 1))
			collision = ((pj.direction == LEFT && npcs[i].direction == RIGHT)
					|| (pj.direction == RIGHT && npcs[i].direction == LEFT));
		if (pj.x == npcs[i].x && (npcs[i].y == pj.y + 1
				|| npcs[i].y == pj.y - 1))
			collision = ((pj.direction == UP && npcs[i].direction == DOWN)
					|| (pj.direction == DOWN && npcs[i].direction == UP));
		if (collision)
			exit_game(LOOSE, game);
		i++;
	}
	if (i < game->n_npcs)
		exit_game(LOOSE, game);
}
