/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:14:40 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/19 21:50:59 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (n / 16)
		i += ft_write_hex(n / 16, c);
	if (c == 'x')
		i += ft_write_char(DHEX[n % 16]);
	else
		i += ft_write_char(UHEX[n % 16]);
	return (i);
}
