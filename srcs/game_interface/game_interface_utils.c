/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_interface_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:09:16 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 17:17:31 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	char_init_values(t_char *charac)
{
	charac->pos_x = 0;
	charac->pos_y = 0;
}

void	*free_map(char ***map)
{
	int	i;

	if (!map || !*map)
		return (NULL);
	i = 0;
	while (map[0][i])
	{
		free(map[0][i]);
		map[0][i] = NULL;
		i++;
	}
	free(*map);
	*map = NULL;
	return (NULL);
}
