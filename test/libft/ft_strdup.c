/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:31:40 by olarseni          #+#    #+#             */
/*   Updated: 2024/09/26 02:07:46 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*result;
	size_t			size;

	size = ft_strlen(s) + 1;
	result = (char *)ft_calloc(size, sizeof(char));
	if (!result)
		return (NULL);
	return (ft_memcpy(result, s, size));
}
