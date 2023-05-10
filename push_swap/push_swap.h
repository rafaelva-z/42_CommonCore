/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:18:08 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/10 12:14:58 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct stack{
	int		number;
	void	*next;
}	t_stack;

void	push_swap(int *seq, int seq_size);
int		input_check(char **input);
int		is_signal(char c);

#endif