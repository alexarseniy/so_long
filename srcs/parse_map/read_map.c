/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:46:50 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/12 20:43:28 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

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

char	**read_map(char *path_file)
{
	int		fd;
	char	*map_line;
	char	**map;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_line = read_map_file(fd);
	close(fd);
	if (!map_line)
		return (NULL);
	map = ft_split(map_line, '\n');
	free(map_line);
	if (!map)
		return (NULL);
	return (map);
}
