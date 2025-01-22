/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:16:48 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 23:29:21 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INTERFACE_H
# define GAME_INTERFACE_H

# include "read_map.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdlib.h>
# include "error_checker.h"
# include <stdbool.h>

# define IMG_WIDTH			32
# define IMG_HEIGHT			32
# define WALL_SPRITE		"textures/wall.xpm"
# define FLOOR_SPRITE		"textures/floor.xpm"
# define PJ_PATH			"textures/pj/tile0"
# define NPC_PATH			"textures/npc/tile0"
# define EXIT_CLOSED		"textures/exit/closed.xpm"
# define EXIT_OPENED		"textures/exit/opened.xpm"
# define COLLECT_PATH		"textures/collectable/collect.xpm"
# define SPRITE_EXTENSION	".xpm"
# define N_CHAR_SPRITES		11
# define MAX_NPCS			100
# define N_COLLECT_SPRITES	3
# define WIN				0
# define LOOSE				1
# define EXIT_KEY			2

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_char
{
	int	x;
	int	y;
	int	direction;
}	t_char;

typedef struct s_count
{
	int	count_steps;
	int	count_collectables;
}	t_count;

typedef struct s_collectable
{
	int		x;
	int		y;
	bool	is_collected;
}	t_collectable;

typedef struct s_exit
{
	int		x;
	int		y;
	bool	is_exit_closed;
}	t_exit;

typedef struct s_sprites
{
	int		width;
	int		height;
	void	*wall;
	void	*floor;
	void	*exit_closed;
	void	*exit_opened;
	void	*collect;
	void	**pj;
	void	**npc;
}	t_sprites;

typedef struct s_game
{
	void					*mlx;
	void					*window;
	int						n_collects;
	int						n_npcs;
	struct s_map			map;
	struct s_char			pj;
	struct s_char			*npcs;
	struct s_count			counter;
	struct s_collectable	*collectables;
	struct s_exit			exit;
	struct s_sprites		sprites;
}	t_game;

void	init_game_interface(t_game *game, char *map_file);
void	init_map(t_game *game, char *map_file);
void	init_pj(t_game *game);
void	init_npcs(t_game *game);
void	init_counter(t_game *game);
void	init_collectable(t_game *game);
void	init_exit(t_game *game);
void	destroy_map(t_game *game);
void	destroy_collectables(t_game *game);
void	destroy_npcs(t_game *game);
void	destroy_game_interface(t_game *game);
void	destroy_sprites(t_game *game);
void	char_init_values(t_char *charac);
void	map_init_values(t_map *map);
void	counter_init_values(t_count *counter);
void	init_sprites(t_game *game);
void	sprites_init_values(t_sprites *sprites);
void	*free_map(char ***map);

#endif
