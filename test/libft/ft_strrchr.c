/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:48:46 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/03 23:26:53 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s) + 1;
	ptr = (char *)s + size - 1;
	while (*ptr != (char)c && size > 0)
	{
		size--;
		ptr--;
	}
	if (!size)
		return (NULL);
	return (ptr);
}
