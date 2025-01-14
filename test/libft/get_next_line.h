/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:46:04 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/09 23:03:50 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_append(char *dest, char *src, size_t nbytes);
size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *str, char c);
char	*ft_ltrim(char *str, size_t nbytes);
char	*gnl_substr(char *str, size_t start, size_t nbytes);

#endif
