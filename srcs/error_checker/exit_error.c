/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:42:05 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 23:46:42 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_checker.h"

void	exit_error(t_error err, t_game *game)
{
	const char	*err_msg[] = {"OK", "Incorrect number of arguments",
		"Failed init game interface", "Failed init mlx",
		"Falied init mlx window", "Invalid map's file name", "Failed read map",
		"Total map size is bigger than 1000",
		"The map is not rectangular", "The map has invalid chars",
		"The map is not rounded by walls",
		"The number of start and/or exit is invalid",
		"The map doesn't contain collectionables",
		"Map doesn't have a valid path", "Failed malloc for NPCS",
		"Failed malloc for collects", "Failed load sprites",
		"Error while setting s_steps to print count_step",
		"Error while setting s_collects to print count_collectables",
		"There's undefined error. Good luck trying to find what failed :)"};

	if (err == OK)
		return ;
	ft_printf("Error\n[%i] %s\n", err, err_msg[err]);
	if (game)
		destroy_game_interface(game);
	exit(err);
}
