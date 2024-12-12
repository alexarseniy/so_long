/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-19 19:14:35 by olarseni          #+#    #+#             */
/*   Updated: 2024-10-19 19:14:35 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_int(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		n *= -1;
		i += write(1, "-", 1);
	}
	if (n / 10)
		i += ft_write_int(n / 10);
	i += ft_write_char(n % 10 + '0');
	return (i);
}
