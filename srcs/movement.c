/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:36 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 17:56:44 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	npcs_update_pos(t_game *game, t_char *npc, int x, int y)
{
	int	i;

	if (check_wall_collision(npc, game->map.map, x, y) ||
		check_npc_collision(npc, game->map.map, x, y))
		return ;
	i = 0;
	while (i < game->n_collects &&
		(game->collectables[i].x != npc->x ||
		game->collectables[i].y != npc->y))
		i++;
	if (i < game->n_collects && !game->collectables[i].is_collected)
		game->map.map[npc->y][npc->x] = 'C';
	else if (game->exit.x == npc->x && game->exit.y == npc->x)
		game->map.map[npc->y][npc->x] = 'E';
	else
		game->map.map[npc->y][npc->x] = '0';
	npc->x += x;
	npc->y += y;
}

void	npcs_move(t_game *game)
{
	int	i;
	int	move;

	i = -1;
	while (++i < game->n_npcs)
	{
		move = rand() % 5;
		if (move == 0)
			continue ;
		if (move == UP)
			npcs_update_pos(game, &(game->npcs[i]), 0, -1);
		if (move == DOWN)
			npcs_update_pos(game, &(game->npcs[i]), 0, 1);
		if (move == LEFT)
			npcs_update_pos(game, &(game->npcs[i]), -1, 0);
		if (move == RIGHT)
			npcs_update_pos(game, &(game->npcs[i]), 1, 0);
		game->npcs[i].direction = move;
	}
	return (0);
}

void	pj_move(t_game *game, int x, int y, int	direction)
{
	int	i;

	i = 0;
	if (check_wall_collision(game->pj, game->map.map, x, y))
		return ;
	game->map.map[y][x] = '0';
	game->pj.x += x;
	game->pj.y += y;
	if (game->map.map[game->pj.y][game->pj.x] == 'C')
	{
		while (i < game->n_collects && (game->collectables[i].x != game->pj.x ||
			game->collectables[i].y != game->pj.y))
			i++;
		if (i < game->n_collects)
		{
			game->collectables[i].is_collected = true;
		}
	}
	game->pj.direction = direction;
}
