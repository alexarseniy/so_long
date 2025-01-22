/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:33:38 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/22 01:01:51 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "game_interface.h"
# include "error_checker.h"

typedef enum e_move
{
	UP = 3,
	DOWN = 0,
	LEFT = 1,
	RIGHT = 2
}	t_enum;

void	update_position_char(t_char *character, int x, int y);
void	pj_move(t_game *game, int x, int y, int move);
void	npcs_move(t_game *game);
void	render(t_game *game);
bool	check_wall_collision(t_char charac, char **map, int x, int y);
bool	check_npc_collision(t_char charac, char **mmap, int x, int y);
void	check_pj_npc_collision(t_game *game);
void	exit_game(int win, t_game *game);
void	mlx_put_counter_window(t_game *game);

#endif
