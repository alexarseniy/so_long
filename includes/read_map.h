/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:59:08 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/01 19:48:10 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>

#define MAPS_PATH "./resources/maps/"

char	**read_map(char *path_file);
void	free_map(char **map);
void	print_map(char	**map);
char	*generate_file_path(char *file_name);

#endif
