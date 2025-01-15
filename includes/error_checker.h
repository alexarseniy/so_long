/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.madrid42.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:41:00 by olarseni          #+#    #+#             */
/*   Updated: 2025/01/15 18:44:28 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ERROR_CHECKER_H
# define ERROR_CHECKER_H

typedef enum e_error
{
	OK = 0,
	ERROR_N_ARGS,
	ERROR_GAME_IS_NULL,
	ERROR_MAP_FILE_NAME,
	ERROR_GENERATING_FILE_PATH,
	ERROR_OPEN_MAP_FILE,
	ERROR_GENERATE_MAP_MATRIX,
	ERROR_READ_MAP,
	ERROR_SET_MAP_SIZE,
	ERROR_INIT_PJ,
	ERROR_INIT_NPCS,
	ERROR_MALLOC_NPCS,
	ERROR_INIT_COLLECTS,
	ERROR_MALLOC_COLLECTS,
	ERROR_LOADING_SPRITES,
	ERROR_VALID_MAP_FILE,
	ERROR_DUPLICATED_START,
	ERROR_DUPLICATED_EXIT,
	ERROR_NO_COLLECTS,
	ERROR_NO_RECTANGLE,
	ERROR_MAP_NOT_ROUNDED_WALLS,
	ERROR_MAP_HAS_NOT_VALID_PATH
}	t_error;

#endif
