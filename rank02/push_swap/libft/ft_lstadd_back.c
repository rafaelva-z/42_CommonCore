/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:57:46 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/19 00:34:06 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/* #include <stdio.h>
int	main()
{
	t_list *list1;
	t_list *list2;
	t_list *list3;

	list1 = ft_lstnew("");
	list2 = ft_lstnew("");
	list3 = ft_lstnew("");

	ft_lstadd_back(&list1, list2);
	ft_lstadd_back(&list2, list3);
	printf("Result: %d", ft_lstsize(list1));
} */