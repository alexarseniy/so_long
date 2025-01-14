/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:20:12 by olarseni          #+#    #+#             */
/*   Updated: 2024/12/09 23:07:42 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*ft_append(char *dest, char *src, size_t nbytes)
{
	char	*result;
	size_t	d_len;
	size_t	i;

	if (!src)
		return (NULL);
	if (!dest)
		d_len = 0;
	else
		d_len = gnl_strlen(dest);
	result = (char *)malloc(d_len + nbytes + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < d_len)
		result[i] = dest[i];
	while (i < d_len + nbytes)
		result[i++] = *src++;
	result[i] = 0;
	return (free(dest), result);
}

char	*gnl_substr(char *str, size_t start, size_t nbytes)
{
	char	*result;
	size_t	i;

	if (!str)
		return (NULL);
	result = (char *)malloc(nbytes + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (*str && i + start < nbytes)
		result[i++ + start] = *str++;
	result[i + start] = 0;
	return (result);
}

char	*ft_ltrim(char *str, size_t nbytes)
{
	char	*result;
	size_t	i;

	if (!str || !nbytes)
		return (free(str), NULL);
	result = (char *)malloc(gnl_strlen(str) - nbytes + 1);
	if (!result)
		return (free(str), NULL);
	i = -1;
	while (str[++i + nbytes])
		result[i] = str[i + nbytes];
	result[i] = 0;
	free(str);
	return (result);
}
