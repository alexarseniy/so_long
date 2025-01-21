/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:49:06 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 17:52:33 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_wall_collision(t_char charac, char **map, int x, int y)
{
	if (map[charac.y + y][characc.x + x] == '1')
		return (true);
	return (false);
}

bool	check_npc_collision(t_char charac, char **map, int x, int y)
{
	if (map[charac.y + y][characc.x + x] == 'N')
		return (true);
	return (false);
}

void	check_pj_npc_collision(t_game *game)
{
	int		i;
	t_char	pj;
	t_char	npcs;

	i = 0;
	pj = game->pj;
	npcs = game->npcs;
	while (i < game->n_npcs && (npcs[i].x != pj.x || npcs[i].y != pj.y))
		i++;
	if (i < game->n_npcs)
		exit_error(ERROR, game);
}
