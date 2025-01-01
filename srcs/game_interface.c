/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarseni <oleksandr.arseniy@student.madri   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:35:12 by oarseni           #+#    #+#             */
/*   Updated: 2025/01/01 20:20:56 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void game_interface_init_struct(t_game_interface *game_interface)
{
	game_interface->mlx = NULL;
	game_interface->window = NULL;
	game_interface->map = NULL;
}

static t_error	init_mlx(t_game_interface *game_interface)
{
	game_interface->mlx	= mlx_init();
	if (!game_interface->mlx)
		return (ERROR_INIT_MLX);
	return (OK);
}

static t_error	init_mlx_window(t_game_interface *game_interface)
{
	game_interface->window = mlx_new_window(game_interface->mlx, 500, 500, 
			"so_long");
	if (!game_interface->window)
		return (ERROR_INIT_MLX_WINDOW);
	return (OK);
}

t_game_interface	init_game_interface(char *map_file_name)
{
	t_game_interface	game_interface;
	t_error				error;

	game_interface_init_struct(&game_interface);
	game_interface.map = read_map(map_file_name);
	error = check_valid_map(game_interface.map);
	if (!error)
		error = init_mlx(&game_interface);
	if (!error)
		error = init_mlx_window(&game_interface);
	if (error)
	{
		destroy_game_interface(game_interface);
		print_error(error);
		exit(error);
	}
	return (game_interface);
}

void	destroy_game_interface(t_game_interface *game_interface)
{
	if (!game_interface)
		return ;
	if (game_interface->map)
		free_map(game_interface->map);
	if (game_interface->window)
		mlx_destroy_window(game_interface->mlx, game_interface->window);
	if (game_interface->mlx)
		mlx_destroy_display(game_interface->mlx);
	free(game_interface->mlx);
	game_interface_init_struct(game_interface);
}
