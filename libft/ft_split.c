/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:41:21 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/03 23:24:24 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	int		is_word;

	words = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word++;
			words++;
		}
		else if (*s == c && is_word)
			is_word--;
		s++;
	}
	return (words);
}

static void	*ft_free_all(char **result, size_t n_words)
{
	size_t	i;

	i = 0;
	while (i < n_words)
		free(result[i++]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**result;
	char	*next_c;

	if (!s)
		return (NULL);
	result = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	i = -1;
	while (*s && result)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		next_c = ft_strchr(s, c);
		if (!next_c)
			next_c = ft_strchr(s, '\0');
		result[++i] = ft_substr(s, 0, next_c - s);
		if (!result[i])
			return (ft_free_all(result, i));
		s = next_c;
	}
	return (result);
}
