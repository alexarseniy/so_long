/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:42:03 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/13 01:55:42 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	init_collectable(t_game *game)
{
	t_collectable	*collects;
	int				n_collects;
	int				i;

	if (!game || !game->map.map)
		exit(1);
	n_collects = count_collects(game->map.map);
	if (!collects || n_collects >= 100)
		exit(1);
	collects = ft_calloc(n_collects + 1, sizeof(t_collectable *));
	if (!collects)
		exit(1);
	i = 0;
	while(i < n_collects + 1)
	{
		collect_init_value(&(collects[i]), COLLECT_PATH);
		if (collect_init_sprites(&(collects[i]), game) != OK)
			exit(1);
		collect_init_position(game->map.map, &(collects[i]));
		i++;
	}
	game->collectables = collects;
}
