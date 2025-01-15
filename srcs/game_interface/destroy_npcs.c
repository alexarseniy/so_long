/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_npcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:46:06 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 16:58:30 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	destroy_npcs(t_game *game)
{
	if (!game)
		exit(1);
	free(game->npcs);
	game->npcs = NULL;
}
