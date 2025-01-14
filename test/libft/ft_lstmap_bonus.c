/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olarseni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 05:41:03 by olarseni          #+#    #+#             */
/*   Updated: 2024/10/02 05:28:55 by olarseni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_node;
	void	*result_content;

	if (!lst || !f || !del)
		return (NULL);
	result_content = f(lst->content);
	if (!result_content)
		return (NULL);
	result_node = ft_lstnew(result_content);
	if (!result_node)
	{
		del(result_content);
		return (NULL);
	}
	if (lst->next)
	{
		result_node->next = ft_lstmap(lst->next, f, del);
		if (!result_node->next)
		{
			ft_lstdelone(result_node, del);
			return (NULL);
		}
	}
	return (result_node);
}
