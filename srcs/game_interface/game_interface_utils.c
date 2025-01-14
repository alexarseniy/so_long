/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_interface_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:09:16 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/13 00:38:14 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	char_init_values(t_char *charac, char *sprite_path)
{
	charac->movement_sprites = NULL;
	charac->pos_x = 0;
	charac->pos_y = 0;
	charac->sprite_path = sprite_path;
	charac->sprite_width = 32;
	charac->sprite_height = 32;
}

static char	*generate_char_sprites_path(t_char *charac, int tile_n)
{
	char	*sprite_num;
	char	*path;
	char	*path_with_extension;

	sprite_num = ft_itoa(tile_n);
	if (!sprite_num)
		return (NULL);
	path = ft_strjoin(charac->sprite_path, sprite_num);
	if (!path)
		return (free(sprite_num), NULL);
	path_with_extension = ft_strjoin(path, SPRITE_EXTENSION);
	return (free(sprite_num), free(path), path_with_extension);
}

t_error	char_init_movement_sprites(t_char *charac, t_game *game)
{
	int		i;
	char	*sprite_path;

	charac->movement_sprites = ft_calloc(N_CHAR_SPRITES + 1, sizeof(void *));
	if (!charac->movement_sprites)
		return (ERROR);
	i = 0;
	while (i < N_CHAR_SPRITES + 1)
	{
		sprite_path = generate_char_sprites_path(charac, i);
		if (!sprite_path)
			return (ERROR);
		charac->movement_sprites[i] = mlx_xpm_file_to_image(game->mlx,
				sprite_path, &(charac->sprite_width), &(charac->sprite_height));
		if (!charac->movement_sprites[i])
			return (free(sprite_path), ERROR);
		free(sprite_path);
		i++;
	}
	return (OK);
}
