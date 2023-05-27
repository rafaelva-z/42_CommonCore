/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:18:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/27 20:00:57 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

// Utils
int		ft_issignal(char c);
int		ft_error(void);
void	ft_bzero_int(int *nb);
t_list	*ft_lstbeforelast(t_list *lst);
int		input_checker(char **input);
t_list	*create_stack(char **argv, int argc);
int		ps_checker(t_list *stack_a, t_list *stack_b);
int     ps_input_checker(char **input);
int		find_cheapest(t_list *stack_a, t_list *stack_b);
void	r_bigtotop(t_list **stack);
int		best_num(t_list stack_a, t_list *stack_b);

// Algorithms
void	ps_bruteforce(t_list **stack_a, t_list **stack_b);
void    ps_newsort(t_list **stack_a, t_list **stack_b, int argc);


// Operations
void	sa(t_list **stack_a, int print);
void	sb(t_list **stack_b, int print);
void	ss(t_list **stack_a, t_list **stack_b, int print);
void	pa(t_list **stack_a, t_list **stack_b, int print);
void	pb(t_list **stack_a, t_list **stack_b, int print);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b, int print);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b, int print);

//others (not necessarily used)
void	heapperm(int *a, int size, int n, t_list **stack_a, t_list **stack_b, int argc);
t_list	*create_stack_int(int *seq, int argc);
void	print_stacks(t_list *stack_a, t_list *stack_b);
void	ft_swap(void *a, void *b, size_t bytes);


#endif