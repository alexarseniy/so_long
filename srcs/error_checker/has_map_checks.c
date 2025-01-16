/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_map_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:27:44 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 15:36:23 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_checker.h"

bool	has_one_start_exit(char **map)
{
	int	i;
	int	j;
	int	n_starts;
	int	n_ends;

	i = 0;
	n_starts = 0;
	n_ends = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				n_starts += 1;
			if (map[i][j] == 'E')
				n_ends += 1;
			j++;
		}
		i++;
	}
	if (n_starts != 1 || n_ends != 1)
		return (false);
	return (true);
}

bool	has_collects(char **map)
{
	int	i;
	int	j;
	int	n_collects;

	n_collects = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				n_collects += 1;
			j++;
		}
		i++;
	}
	if (!n_collects)
		return (false);
	return (true);
}

bool	has_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(VALID_CHARS, map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
