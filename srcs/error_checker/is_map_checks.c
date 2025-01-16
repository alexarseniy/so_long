/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:55:09 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 15:26:32 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_checker.h"

bool is_valid_map_file(char *map_file)
{
	char	*extension;
	if (!map_file)
		return (false);
	extension = ft_strrchr(map_file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5))
		return (false);
	return (true);
}

bool	is_rectangle_map(char **map)
{
	int	i;
	int	first_row_size;

	first_row_size = ft_strlen(map[0]);
	i = 0;
	while (map[i] && (size_t)first_row_size == ft_strlen(map[i]))
		i++;
	if (map[i])
		return (false);
	return (true);
}

bool	is_rounded_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || !map[i + 1]) && map[i][j] != '1')
				return (false);
			else if ((j == 0 || !map[i][j + 1]) && map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
