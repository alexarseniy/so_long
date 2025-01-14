/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:06:13 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/19 21:30:22 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_checker(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_write_char(va_arg(arg, int));
	else if (c == 's')
		count = ft_write_str(va_arg(arg, char *));
	else if (c == 'p')
		count = ft_write_ptr(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		count = ft_write_int(va_arg(arg, int));
	else if (c == 'u')
		count = ft_write_uint(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_write_hex(va_arg(arg, size_t), c);
	else if (c == '%')
		count = write(1, "%", 1);
	else
		count = -1;
	return (count);
}

int	ft_printf(char const *s, ...)
{
	int		count;
	int		write_ret;
	va_list	lst;

	count = 0;
	write_ret = 0;
	va_start(lst, s);
	while (*s)
	{
		if (*s && *s == '%')
		{
			write_ret = ft_conv_checker(*(s + 1), lst);
			if (write_ret == -1)
				return (-1);
			count += write_ret;
			s += 2;
		}
		else
			count += write(1, s++, 1);
	}
	va_end(lst);
	return (count);
}
