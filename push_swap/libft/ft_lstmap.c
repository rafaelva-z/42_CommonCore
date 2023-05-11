/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:42:06 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/11 11:32:56 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new = ft_lstnew(lst->nb);
	tmp = lst->next;
	while (tmp)
	{
		ft_lstadd_back(&new, ft_lstnew(tmp->nb));
		tmp = tmp->next;
	}
	free(tmp);
	return (new);
}
