/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_a2b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:03:13 by pramos            #+#    #+#             */
/*   Updated: 2024/02/12 12:27:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_sort(t_stack **stack_b, t_stack **stack_a, int i, int division)
{
	int	tope;
	int	div;
	int	biggest;

	biggest = stack_biggestindex(*stack_a);
	div = check_divisions(*stack_a, i);
	//printf("div :: %i\n", div);
	tope = division;
	//printf("tope :: %i\n", tope);
	division = division - div;
	//printf("division :: %i\n", division);
	//guarda los 3 valores mas grandes
	if ((biggest == (*stack_a)->index
			|| biggest - 1 == (*stack_a)->index
			|| biggest - 2 == (*stack_a)->index))
		ra(stack_a); 
	else if (division - div == div * i)
		pb(stack_a, stack_b);
	else if (division > (*stack_a)->index)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else if (tope > (*stack_a)->index)
		pb(stack_a, stack_b);
	else
		ra(stack_a);
}

int	serch_num_a2b(t_stack **stack_a, t_stack **stack_b, int division)
{
	t_stack	*stack_aux;
	int		i;

	i = 0;
	if (stack_b == NULL)
		return (i);
	stack_aux = (*stack_a);
	while (stack_aux == NULL)
	{
		if (stack_aux->index <= division)
		{
			i = 1;
			break ;
		}
		stack_aux = stack_aux->next;
	}
	return (i);
}

void	sort_a2b(t_stack **stack_a, t_stack **stack_b, int division, int i)
{
	int		div;
	int		size;
	int		j;
	int		k;

	//printf("division :: %i\n", division);
	div = division;
	division = div * 2;
	k = 0;
	while ((*stack_a)->next->next->next != 0)
	{
		j = 0;
		size = lstsize(*stack_a);
		while (j < size)
		{
			first_sort(stack_b, stack_a, i, division);
			if (serch_num_a2b(stack_a, stack_b, division) == 1)
				break ;
			j++;
			
		}
		k++;
		//printf("division :: %i\n", division);
		division = division + (div * 2);
		//print_stack(*stack_b);
		//if(k == 1)
		//	return ;
	}
}
