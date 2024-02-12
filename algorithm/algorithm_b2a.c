/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_b2a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:37:49 by pramos            #+#    #+#             */
/*   Updated: 2024/02/12 12:31:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	second_sort(t_stack **stack_b, t_stack **stack_a, int division)
{
	int	i;
	int	last_a;
	int	index;

	i = 0;
	index = (*stack_b)->index;
	last_a = lstlast(*stack_a)->index + 1;
	if ((index > 0 && index == division) || index == last_a)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}	
	else if (stack_b && (*stack_b)->index + 1 == (*stack_a)->index)
		pa(stack_a, stack_b);
	else
	{
		rb(stack_b);
		i++;
	}
	return (i);
}

void	sort_chunk_2(t_stack **stack_a, t_stack **stack_b, int division, int i)
{
	while (i-- > 0 && division > 0)
	{
		rrb(stack_b, 0);
		if (stack_b && (*stack_b)->index + 1 == (*stack_a)->index)
			pa(stack_a, stack_b);
		else if (((*stack_b)->index > 0 && (*stack_b)->index == division)
			|| (*stack_b)->index == lstlast(*stack_a)->index + 1)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if (serch_num_b2a(stack_a, stack_b, division) == 1 && division > 0)
			sort_chunk(stack_a, stack_b, division);
	}
}

void	sort_chunk(t_stack **stack_a, t_stack **stack_b, int division)
{
	int	i;

	i = 0;
	while (lstsize(*stack_a) < 1 + stack_biggestindex(*stack_a)
		&& stack_b && (*stack_b)->index >= division)
	{
		i += second_sort(stack_b, stack_a, division);
		if (lstsize(*stack_a) < 1 + stack_biggestindex(*stack_a)
			&& serch_num_b2a(stack_a, stack_b, division) == 0 && division > 0)
			break ;
	}
	sort_chunk_2(stack_a, stack_b, division, i);
	if (stack_b && lstlast(*stack_a)->index + 1 == (*stack_a)->index)
		while (lstlast(*stack_a)->index + 1 == (*stack_a)->index)
			rra(stack_a, 0);
}

void	sort_b2a_2(t_stack **stack_a, t_stack **stack_b, int division)
{
	division = (*stack_b)->index;
	rrb(stack_b, 0);
	if (stack_b && (*stack_b)->index + 1 == (*stack_a)->index)
		pa(stack_a, stack_b);
	else if (division > 0 && (*stack_b)->index == lstlast(*stack_a)->index + 1)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	sort_b2a(t_stack **stack_a, t_stack **stack_b, int division, int i)
{
	int	div;
	int	j;

	div = division;
	division = division - (division - ((div / i) * i));
	//mientras que el tamaño de a no sea el mayor index no pares
	while (lstsize(*stack_a) < 1 + stack_biggestindex(*stack_a))
	{
		j = 0;
		//no paramos hasta que encontremos un numero que sea distinto al de la caja 
		//en la que estamos trabvajando
		if ((*stack_b)->index >= division)
			while (stack_b && (*stack_a)->index > division)
				sort_chunk(stack_a, stack_b, division);
		else
		{
			while (j++ < (div / i)
				&& (*stack_b)->index >= div / i && division != div)
				sort_b2a_2(stack_a, stack_b, division);
		}
		division = division - div / i;
	}
}
