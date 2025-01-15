/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_collectable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:50:16 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 16:59:19 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	destroy_collectables(t_game *game)
{
	if (!game)
		exit (1);
	free(game->collectables);
	game->collectables = NULL;
}
