/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:42:06 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/10 16:54:35 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new;
// 	t_list	*tmp;

// 	if (!lst)
// 		return (NULL);
// 	new = ft_lstnew(f(lst->content));
// 	tmp = lst->next;
// 	while (tmp)
// 	{
// 		ft_lstadd_back(&new, ft_lstnew(f(tmp->content)));
// 		tmp = tmp->next;
// 	}
// 	del(tmp);
// 	return (new);
// }
