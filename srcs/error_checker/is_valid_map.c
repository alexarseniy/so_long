/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:37:32 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 16:09:18 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_checker.h"

t_error	is_valid_map(char **map)
{
	if (!map)
		return (ERROR);
	if (!is_rectangle_map(map))
		return (ERROR_NO_RECTANGLE);
	if (!has_valid_chars(map))
		return (ERROR_INVALID_CHARS);
	if (!is_rounded_walls(map))
		return (ERROR_MAP_NOT_ROUNDED_WALLS);
	if (!has_one_start_exit(map))
		return (ERROR_N_START_EXIT);
	if (!has_collects(map))
		return (ERROR_NO_COLLECTS);
	if (!has_valid_path(map))
		return (ERROR_MAP_PATH);
	return (OK);
}
