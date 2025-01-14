/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:30:02 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/19 21:56:20 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# define UHEX	"0123456789ABCDEF"
# define DHEX	"0123456789abcdef"

int	ft_printf(char const *s, ...);
int	ft_write_char(char c);
int	ft_write_str(char *s);
int	ft_write_ptr(void *ptr);
int	ft_write_int(int n);
int	ft_write_uint(unsigned int n);
int	ft_write_hex(unsigned int n, char c);

#endif
