/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:45:33 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/10 18:28:27 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include <fcntl.h>
# include "libft.h"
# include <stdlib.h>

# define MAP_PATH "maps/"

char	**read_map(char *file_name);
void	print_map(char **map);

#endif
