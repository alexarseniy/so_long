/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:13:56 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/10 18:30:50 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_utils.h"

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
