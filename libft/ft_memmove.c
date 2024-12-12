/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:07:15 by olarseni          #+#    #+#             */
/*   Updated: 2024/09/20 00:54:13 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		if (ptr_dest > ptr_src)
			*(ptr_dest + n) = *(ptr_src + n);
		else
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}
