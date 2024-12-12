/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:10:07 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/19 16:28:37 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_uint(unsigned int n)
{
	int	i;

	i = 0;
	if (n / 10)
	{
		i += ft_write_int(n / 10);
		i += ft_write_int(n % 10);
	}
	else
		i += ft_write_int(n % 10);
	return (i);
}
