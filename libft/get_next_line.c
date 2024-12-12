/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:47:29 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/09 23:05:51 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_buff(char *st_buff, int fd)
{
	char	*temp;
	char	*buff;
	ssize_t	nbytes;

	nbytes = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(st_buff), NULL);
	buff[BUFFER_SIZE] = 0;
	while (nbytes && !gnl_strchr(st_buff, '\n'))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes < 0)
			return (free(st_buff), free(buff), NULL);
		temp = st_buff;
		st_buff = ft_append(st_buff, buff, nbytes);
		if (!st_buff)
			return (free(temp), free(buff), NULL);
	}
	return (free(buff), st_buff);
}

static char	*get_line(char *str)
{
	char	*result;
	char	*nl_ptr;

	nl_ptr = gnl_strchr(str, '\n');
	if (!nl_ptr)
		nl_ptr = gnl_strchr(str, '\0') - 1;
	result = gnl_substr(str, 0, (size_t)(nl_ptr - str) + 1);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*st_buff;
	char		*nl_ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st_buff = init_buff(st_buff, fd);
	if (!st_buff)
		return (NULL);
	result = get_line(st_buff);
	if (!result)
		return (free(st_buff), st_buff = NULL, NULL);
	nl_ptr = gnl_strchr(st_buff, '\n');
	if (!nl_ptr)
		nl_ptr = gnl_strchr(st_buff, '\0') - 1;
	st_buff = ft_ltrim(st_buff, (size_t)(nl_ptr - st_buff) + 1);
	if (!st_buff)
		return (free(result), NULL);
	return (result);
}
