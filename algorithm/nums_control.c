/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:28:57 by pramos            #+#    #+#             */
/*   Updated: 2023/05/24 23:34:45 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_biggestindex(t_stack *stack_a)
{
	t_stack	*stack_aux1;
	int		index;

	index = 0;
	stack_aux1 = stack_a;
	while (stack_aux1)
	{
		if (stack_aux1->index > index)
			index = stack_aux1->index;
		stack_aux1 = stack_aux1->next;
	}
	return (index);
}

int	stack_biggestnum(t_stack *stack_a)
{
	t_stack	*stack_aux1;
	int		biggest;
	int		index;

	index = 0;
	biggest = 0;
	stack_aux1 = stack_a;
	while (stack_aux1)
	{
		if (stack_aux1->index > index)
		{
			index = stack_aux1->index;
			biggest = stack_aux1->content;
		}
		stack_aux1 = stack_aux1->next;
	}
	return (biggest);
}

int	stack_lower(t_stack *stack_a)
{
	t_stack	*stack_aux1;
	int		lower;
	int		index;

	index = 0;
	lower = 0;
	stack_aux1 = stack_a;
	while (stack_aux1)
	{
		if (stack_aux1->index == index)
			lower = stack_aux1->content;
		stack_aux1 = stack_aux1->next;
	}
	return (lower);
}

void	index_satck(t_stack **stack_a)
{
	t_stack	*stack_aux1;
	t_stack	*stack_aux2;

	stack_aux1 = (*stack_a);
	while (stack_aux1)
	{
		stack_aux2 = (*stack_a);
		while (stack_aux2)
		{
			if (stack_aux1->content > stack_aux2->content)
				stack_aux1->index += 1;
			stack_aux2 = stack_aux2->next;
		}
		stack_aux1 = stack_aux1->next;
	}
}
