/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:46:50 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/01 19:48:24 by oarseniy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"

void	print_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		ft_printf("%s\n", map[i++]);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static char	*read_map_file(int fd)
{
	char	*line;
	char	*result;
	char	*buff;

	result = NULL;
	buff = NULL;
	while (1)
	{
		free(buff);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!buff)
			buff = ft_strdup(line);
		else
			buff = ft_strjoin(result, line);
		free(line);
		free(result);
		result = ft_strdup(buff);
		if (!result || !buff)
			return (NULL);
	}
	return (result);
}

char	*generate_file_path(char *file_name)
{
	char	*file_path;

	if (!ft_strchr(file_name, '/'))
		file_path = ft_strjoin(MAPS_PATH, file_name);
	else
		file_path = ft_strjoin("", file_name);
	return (file_path);
}

char	**read_map(char *file_name)
{
	int		fd;
	char	*file_path;
	char	*map_line;
	char	**map;

	file_path = generate_file_path(file_name);
	if (!file_path)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_line = read_map_file(fd);
	close(fd);
	if (!map_line)
		return (NULL);
	map = ft_split(map_line, '\n');
	free(file_path);
	file_path = NULL;
	free(map_line);
	if (!map)
		return (NULL);
	return (map);
}
