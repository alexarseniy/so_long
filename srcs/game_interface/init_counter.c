/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:40:35 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/10 21:41:46 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_interface.h"

void	init_counter(t_count *counter)
{
	counter->count_steps = 0;
	counter->count_collectables = 0;
}
