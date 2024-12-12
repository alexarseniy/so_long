/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:39:45 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/12 21:41:39 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKER_H
# define MAP_CHECKER_H

typedef enum e_error
{
	OK = 0,
	ERROR
}	t_error;

t_error	check_valid_map(char **map);

#endif
