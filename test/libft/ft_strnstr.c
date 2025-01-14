/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:54:12 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/03 23:26:21 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	i = 0;
	little_len = ft_strlen(little);
	while (big[i] && i < len)
	{
		if (!ft_strncmp(big + i, little, little_len) && little_len <= len - i)
			return ((char *)big + i);
		else
			i++;
	}
	return (NULL);
}
