/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:16:48 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/13 02:03:17 by olarseni         ###   ########.fr       */
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
# define N_CHAR_SPRITES		11
# define PJ_PATH			"textures/pj/tile0"
# define NPCS_PATH			"textures/npc/tile0"
# define MAX_NPCS			100
# define SPRITE_EXTENSION	".xpm"
# define EXIT_CLOSED		"textures/exit/closed.xpm"
# define EXIT_OPENED		"textures/exit/opened.xpm"
# define N_COLLECT_SPRITES	3
# define COLLECT_PATH		"textures/collectable/collect.xpm"

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	void	*wall_sprite;
	void	*floor_sprite;
	void	*exit_closed;
	void	*exit_opened;
	void	*collectable_sprites;
	bool	is_exit_closed;
}	t_map;

typedef struct s_char
{
	void	**movement_sprites;
	int		pos_x;
	int		pos_y;
	char	*sprite_path;
	int		sprite_width;
	int		sprite_height;
} t_char;

typedef struct s_count
{
	int	count_steps;
	int	count_collectables;
} t_count;

typedef struct s_collectable
{
	int		x;
	int		y;
} t_collectable;

typedef struct s_game
{
	void					*mlx;
	void					*window;
	struct s_map			map;
	struct s_char			pj;
	struct s_char			*npcs;
	struct s_count			counter;
	struct s_collectable	*collectables;
}	t_game;

void	init_game_interface(t_game *game, char *map_file);
void	init_map(t_game *game, char *map_file);
void	init_pj(t_game *game);
void	init_npcs(t_game *game);
void	init_counter(t_count *counter);
void	init_collectable(t_collectable **collectables);
void	destroy_counter(t_count *count);
void	destroy_npcs(t_char **npc);
void	destroy_pj(t_char *pj);
void	destroy_map(t_map *map);
void	destroy_collectables(t_collectable **collectables);
void	destroy_game_interface(t_game *game);
void	char_init_values(t_char *charac, char *sprite_path);
t_error	char_init_movement_sprites(t_char *charac, t_game *game);


#endif
