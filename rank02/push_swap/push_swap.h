/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:18:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/06/16 19:08:30 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

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

void	rb_totop(t_list **stack_b, int nb_pos);
void	ra_totop(t_list **stack_a, int nb_pos);

// Algorithms
void	ps_bruteforce(t_list **stack_a, t_list **stack_b);
void	ps_newsort(t_list **stack_a, t_list **stack_b);

// Utils
int		ft_issignal(char c);
int		ft_error(void);
void	ft_bzero_int(int *nb);
t_list	*create_stack(char **argv, int argc);
t_list	*ft_lstbeforelast(t_list *lst);
int		ps_solve_checker(t_list *stack_a, t_list *stack_b);
int		ps_input_checker(char **input);
int		find_cheapest(t_list *stack_a, t_list *stack_b);
int		find_bestnum(t_list stack_a, t_list *stack_b);
int		lst_biggest_nb_pos(t_list *stack);
int		lst_smallest_nb_pos(t_list *stack);
void	free_stacks(t_list **stack_a, t_list **stack_b);
t_list	*ps_newsort_moves(t_list **lst, int nb, int *moves);

//Debug
void	print_stacks(t_list *stack_a, t_list *stack_b);
void	print_solve(int *solve, int argc);

#endif