/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:26:47 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/28 00:30:22 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_checker.h"
#include "libft.h"
#include <stdbool.h>

bool	has_min_one_C(char **map)
{
	int	i;
	int	j;
	int	n_collectable;

	i = 0;
	n_collectable = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				n_collectable++;
			j++;
		}
		i++;
	}
	if (n_collectable == 0)
		return (false);
	return (true);
}

bool	has_one_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && map[i][j] && map[i][j] != 'E')
	{
		j = 0;
		while (map[i][j] && map[i][j] != 'E')
			j++;
		i++;
	}
	if (map[i][j] == 'E')
		return (true);
	return (false);
}

bool	is_valid_file_name(char *file_name)
{
	char	*ext;

	ext = ft_strrchr(file_name, '.');
	if (ext && !ft_strncmp(ext, ".ber", 5))
		return (true);
	return (false);
}
