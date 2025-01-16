/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:42:05 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 17:07:45 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_checker.h"

static const char	*get_err_msg(t_error err)
{
	int			i;
	const char	*err_msg[] = {"OK", "Incorrect number of arguments",
		"Failed init game interface", "Failed init mlx",
		"Falied init mlx window", "Invalid map's file name", "Failed read map",
		"The map is not rectangular", "The map has invalid chars",
		"The map is not rounded by walls",
		"The number of start and/or exit is invalid",
		"The map doesn't contain collectionables",
		"Map doesn't have a valid path", "Failed malloc for NPCS",
		"Failed malloc for collects", "Failed load sprites",
		"There's undefined error. Good luck trying to find what failed :)"};

	i = 0;
	while (err_msg[i])
		i++;
	if (i <= (int)err)
		return (err_msg[i - 1]);
	return (err_msg[err]);
}

void	exit_error(t_error err, t_game *game)
{
	const char	*err_msg = get_err_msg(err);

	if (err == OK)
		return ;
	ft_printf("Error\n[%i] %s\n", err, err_msg);
	if (game)
		destroy_game_interface(game);
	exit(err);
}
