/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:42:05 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/21 23:28:59 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	exit_game(int win, t_game *game)
{
	const char	*msg[] = {"You win!", "You Lose!", "Game has finished!"};

	ft_printf("%s\n", msg[win]);
	if (game)
		destroy_game_interface(game);
	exit(0);
}
