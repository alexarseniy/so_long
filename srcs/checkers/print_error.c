/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:52:14 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/28 02:51:44 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_checker.h"

t_error	print_error(t_error error)
{
	if (error == OK)
		return (error);
	ft_printf("Error\n");
	if (error == ERROR)
		ft_printf("Undefined error\n");
	if (error == ERROR_MAP_NOT_RECTANGLE)
		ft_printf("Map is not a valid rectangle\n");
	else if (error == ERROR_MAP_HAS_INVALID_CHAR)
		ft_printf("Map has invalid chars\n");
	else if (error == ERROR_NOT_ROUNDED_BY_WALLS)
		ft_printf("Map is not rounded by walls\n");
	else if (error == ERROR_NUMBER_OF_INIT_EXIT_CHARS)
		ft_printf("Map has an invalid number of init and/or exit chars\n");
	else if (error == ERROR_NOT_COLLECTABLES_FOUND)
		ft_printf("Map doesn't have collectables\n");
	else if (error == ERROR_NOT_VALID_PATH)
		ft_printf("Map doesn't have a valid path\n");
	else if (error == ERROR_INVALID_NUMBER_ARGUMENTS)
		ft_printf("This program need 1 argument\n");
	else if (error == ERROR_INVALID_FILE_NAME)
		ft_printf("Invalid file name extension\n");
	else if (error == ERROR_MAP)
		ft_printf("Error while reading/processing the map file\n");
	return (error);
}
