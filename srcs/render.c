/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:17:38 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/23 00:00:45 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*sprite_to_render(char c, t_game *game)
{
	void				*img;
	static unsigned int	sprite_select = 0;

	if (sprite_select >= 3)
		sprite_select = 0;
	if (c == '1')
		img = (game->sprites.wall);
	else if (c == '0')
		img = (game->sprites.floor);
	else if (c == 'P')
		img = (game->sprites.pj[sprite_select + game->pj.direction * 3]);
	else if (BONUS && c == 'N')
		img = (game->sprites.npc[rand() % 12]);
	else if (c == 'E' && game->exit.is_exit_closed)
		img = (game->sprites.exit_closed);
	else if (c == 'E' && !game->exit.is_exit_closed)
		img = (game->sprites.exit_opened);
	else
		img = (game->sprites.collect);
	sprite_select++;
	return (img);
}

static void	update_map(t_game *game)
{
	int	i;

	game->map.map[game->pj.y][game->pj.x] = 'P';
	i = 0;
	while (i < game->n_npcs)
	{
		game->map.map[game->npcs[i].y][game->npcs[i].x] = 'N';
		i++;
	}
}

void	render(t_game *game)
{
	int		i;
	int		j;
	void	*image;

	mlx_clear_window(game->mlx, game->window);
	if (!game || !game->map.map)
		exit_error(ERROR, game);
	update_map(game);
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			image = sprite_to_render(game->map.map[i][j], game);
			mlx_put_image_to_window(game->mlx, game->window, image, j * 32,
				i * 32);
			j++;
		}
		i++;
	}
	mlx_put_counter_window(game);
}
