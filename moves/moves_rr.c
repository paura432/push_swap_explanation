/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:22:52 by pramos            #+#    #+#             */
/*   Updated: 2023/06/05 18:22:31 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack_a, int i)
{
	int		aux;
	int		index;
	t_stack	*stack_aux;
	t_stack	*stack_aux2;

	if (stack_a == NULL)
		return ;
	stack_aux = *stack_a;
	index = stack_aux->index;
	aux = lstlast(stack_aux)->content;
	stack_aux2 = lstlast(stack_aux);
	while (stack_aux->next->next)
	{
		stack_aux = stack_aux->next;
		index = stack_aux->next->index;
	}
	stack_aux->next = NULL;
	lstadd_front(stack_a, (lstnew(aux, index)));
	free(stack_aux2);
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int i)
{
	int		aux;
	int		index;
	t_stack	*stack_aux;
	t_stack	*stack_aux2;

	if (stack_b == NULL)
		return ;
	stack_aux = *stack_b;
	aux = lstlast(stack_aux)->content;
	stack_aux2 = lstlast(stack_aux);
	while (stack_aux->next->next)
	{
		stack_aux = stack_aux->next;
		index = stack_aux->next->index;
	}
	stack_aux->next = NULL;
	lstadd_front(stack_b, (lstnew(aux, index)));
	free(stack_aux2);
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	i = 1;
	if (stack_b == NULL && stack_a == NULL)
		return ;
	rra(stack_a, i);
	rrb(stack_b, i);
	write(1, "rrr\n", 4);
}
