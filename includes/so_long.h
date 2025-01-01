/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:30:48 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/01 19:56:43 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "read_map.h"
# include "map_checker.h"

typedef struct s_game_interface
{
	void	*mlx;
	void	*window;
	char	**map;
} t_game_interface;

t_game_interface	init_game_interface();
void				destroy_game_interface();

#endif
