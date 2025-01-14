/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:37:26 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/03 23:20:36 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_len(int n)
{
	int	result;

	result = 1;
	if (n < 0)
		result++;
	while (n / 10 != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n_len;

	n_len = ft_len(n);
	result = ft_calloc((n_len + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (n / 10 != 0)
	{
		result[n_len - 1] = ft_abs((n % 10)) + '0';
		n /= 10;
		n_len--;
	}
	result[n_len - 1] = ft_abs((n % 10)) + '0';
	if (n < 0)
		result[0] = '-';
	return (result);
}
