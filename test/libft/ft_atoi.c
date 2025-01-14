/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:39:28 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/06 22:21:02 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(unsigned char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char	*nptr)
{
	int		result;
	int		sign;
	char	*ptr_aux;

	result = 0;
	sign = 1;
	ptr_aux = (char *)nptr;
	while (ft_isspace(*ptr_aux))
		ptr_aux++;
	if (*ptr_aux == '-')
		sign = -1;
	if (*ptr_aux == '-' || *ptr_aux == '+')
		ptr_aux++;
	while (*ptr_aux && ft_isdigit(*ptr_aux))
		result = result * 10 + (*ptr_aux++ - '0');
	return (result * sign);
}
