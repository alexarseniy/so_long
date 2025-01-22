/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:31:12 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/22 00:38:48 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_counter_window(t_game *game)
{
	char	*s_steps;
	char	*s_collects;
	char	*n_steps;
	char	*n_collects;

	n_steps = ft_itoa(game->counter.count_steps);
	n_collects = ft_itoa(game->counter.count_collectables);
	if (!n_steps || !n_collects)
		exit_error(ERROR_SETTING_N_STEPS_COLLECTS, game);
	s_steps = ft_strjoin("Steps: ", n_steps);
	s_collects = ft_strjoin("Collects: ", n_collects);
	if (!s_steps || !s_collects)
		exit_error(ERROR_SETTING_S_STEPS_COLLECTS, game);
	mlx_string_put(game->mlx, game->window, 105, 16, 0xff10ff, s_steps);
	mlx_string_put(game->mlx, game->window, 5, 16, 0xff10ff, s_collects);
	ft_printf("Steps : %s\n", s_steps);
	ft_printf("Steps : %s\n", s_collects);
	free(n_steps);
	free(s_steps);
	free(n_collects);
	free(s_collects);
}
