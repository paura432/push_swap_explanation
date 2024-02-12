/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:58:13 by pramos            #+#    #+#             */
/*   Updated: 2023/09/12 19:36:42 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct t_list_stack
{
	int					content;
	int					index;
	struct t_list_stack	*next;
}t_stack;

int		main(int argc, char **argv);
void	ft_inistack(int argc, char **argv, t_stack **stack_a);
int		check_doubles(t_stack *stack_a);
int		check_errors(char **argv, t_stack *stack_a);
t_stack	*lstlast(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
int		lstsize(t_stack *lst);
t_stack	*lstnew(int content, int index);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, int i);
void	rrb(t_stack **stack_b, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b, int i);

void	init_algorithm(t_stack **stack_a, t_stack **stack_b);
void	index_satck(t_stack **stack_a);
int		stack_biggestindex(t_stack *stack_a);
int		stack_biggestnum(t_stack *stack_a);
int		stack_lower(t_stack *stack_a);
void	litle_sort(t_stack **stack_a);
int		check_divisions(t_stack *stack_a, int i);
void	first_sort(t_stack **stack_b, t_stack **stack_a, int i, int division);
void	print_stack(t_stack *stack_a);
void	sort_a2b(t_stack **stack_a, t_stack **stack_b, int division, int i);
void	sort_b2a(t_stack **stack_a, t_stack **stack_b, int division, int i);
int		second_sort(t_stack **stack_b, t_stack **stack_a, int division);
void	sort_chunk(t_stack **stack_a, t_stack **stack_b, int division);
int		serch_num_b2a(t_stack **stack_a, t_stack **stack_b, int division);
int		serch_num_a2b(t_stack **stack_a, t_stack **stack_b, int division);
void	sort_chunk_2(t_stack **stack_a, t_stack **stack_b, int division, int i);
void	free_stack(t_stack *stack);
void	sort_b2a_2(t_stack **stack_a, t_stack **stack_b, int division);
void	ft_free(char **matriz, int i);

#endif
