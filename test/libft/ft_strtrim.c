/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:22:43 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/03 23:27:12 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*result;
	char const		*end_str;
	size_t			size;

	if (!s1)
		return (NULL);
	end_str = s1 + ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1) + 1;
	while (ft_strrchr(set, *end_str) && size - 1 > 0)
	{
		size--;
		end_str--;
	}
	result = ft_calloc(size, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcat(result, s1, size);
	return (result);
}
