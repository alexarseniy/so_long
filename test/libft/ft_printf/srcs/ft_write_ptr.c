/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:02:40 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/19 22:40:08 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_ptrhex(size_t n)
{
	int	i;

	i = 0;
	if (n / 16)
		i += ft_write_ptrhex(n / 16);
	i += ft_write_char(DHEX[n % 16]);
	return (i);
}

int	ft_write_ptr(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_write_ptrhex((size_t)ptr);
	return (i);
}
