/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:11:26 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/06 22:19:26 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	return (ft_memset(result, 0, nmemb * size));
}
