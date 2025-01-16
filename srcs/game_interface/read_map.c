/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:43:20 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/16 13:30:23 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "game_interface.h"

/*
 * Function: print_map
 * -------------------
 *  @brief Print line by line the map stored in char **map var
 *
 *  @param map stores the map readed from the file
 *
 *  @return void
 */
void	print_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

/*
 * Function: generate_file_path
 * ----------------------------
 * @brief Check if the string 'file_name' is a complet path for the map. If yes,
 * it returns it, otherwise, it generate the fullpath.
 *
 * @params file_name is a string that contain the file_name given to the program
 * as a parameter
 *
 * @returns return file_name if it is a full path or the generated full path
 * using ft_strjoin
 */
static char	*generate_file_path(char *file_name)
{
	if (!file_name)
		return (NULL);
	else if (ft_strrchr(file_name, '/'))
		return (ft_strdup(file_name));
	else
		return (ft_strjoin(MAP_PATH, file_name));
}

/*
 * Function: generate_map_matrix
 * -----------------------------
 *  @brief Generate a map as a matrix after read it from the file, given its
 *  descriptor 'fd'. First, it reads line by line appending each line to a var
 *  full_map. Once the file is fully readed, the function split the full_map by
 *  the new line char.
 *
 *  @param fd A file descriptor that contains the map.
 *
 *  @return map return the splitted map, previously, freeing the memmory used by
 *  full_map var..
 */
static char	**generate_map_matrix(int fd)
{
	char	*map_line;
	char	*full_map;
	char	*temp;
	char	**map;

	map_line = NULL;
	full_map = NULL;
	temp = NULL;
	map = NULL;
	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			break ;
		temp = ft_append(full_map, map_line, ft_strlen(map_line));
		if (!temp)
			return (free(map_line), NULL);
		full_map = temp;
		free(map_line);
	}
	map = ft_split(full_map, '\n');
	return (free(full_map), map);
}

/*
 * Function: read_map
 * ------------------
 *  @brief Read the map file and return the map in matrix format. First, it
 *  checks if the given file_name is a full path o generate the full file path
 *  using the function generate_file_path. Then, open the file storing its file
 *  descriptor in 'fd' var. Then, generate the map matrix with the function 
 *  generate_map_matrix and store its in char **map variable, which one is
 *  returned. Before returning the map, the streaming file is closed and the
 *  memmory of file_path file is freed.
 *
 *  @param file_name Contains the file name or path where the map is stored.
 *
 *  @return map Contains the map readed from the file
 */
char	**read_map(char *file_name)
{
	char	*file_path;
	char	**map;
	int		fd;

	if (!file_name)
		return (NULL);
	file_path = generate_file_path(file_name);
	if (!file_path)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (free(file_path), NULL);
	map = generate_map_matrix(fd);
	close(fd);
	if (!map)
		return (free(file_path), NULL);
	return (free(file_path), map);
}
