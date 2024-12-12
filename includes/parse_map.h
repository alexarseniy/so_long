/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:59:08 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/12 21:39:16 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>

char	**read_map(char *path_file);
void	free_map(char **map);
void	print_map(char	**map);

#endif
