/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:37:53 by pramos            #+#    #+#             */
/*   Updated: 2024/02/12 12:30:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	litle_sort(t_stack **stack_a)
{
	int	biggest;

	biggest = stack_biggestindex(*stack_a);
	if ((*stack_a)->index == biggest)
		ra(stack_a);
	else if ((*stack_a)->next->index == biggest)
		rra(stack_a, 0);
	if ((*stack_a)->index == biggest - 1)
		sa(*stack_a);
}

int	check_divisions(t_stack *stack_a, int i)
{
	int	divisions;

	divisions = stack_biggestindex(stack_a) + 1;
	//dividira divisions por i en este caso 100 / 10 = 10 divisiones
	divisions /= i;
	return (divisions);
}

void	init_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	divisions;
	int	i;

	i = 10;
	//crea los index
	index_satck(stack_a);
	//si es mayor de 200 usa un numero menor de vueltas
	if (stack_biggestindex(*stack_a) + 1 > 200)
		i = 16;
	//checkeamos el numero de cajas que crearemos y divisionm sera
	//el numero mas grande de la caja mas pequeña
	divisions = check_divisions(*stack_a, i);
	//printf("division :: %i\n", divisions);
	sort_a2b(stack_a, stack_b, divisions, i);
	//return ;
	//ahora division sera el index mas grande del stack
	divisions = stack_biggestindex(*stack_a) + 1;
	//ordenara los tres primeros numeros del stack_a
	litle_sort(stack_a);
	//ordenara los numeros de b hacia a
	sort_b2a(stack_a, stack_b, divisions, i);
}

int	serch_num_b2a(t_stack **stack_a, t_stack **stack_b, int division)
{
	t_stack	*stack_aux;
	int		i;

	i = 0;
	if (stack_b == NULL)
		return (i);
	stack_aux = (*stack_b);
	while (stack_aux->index >= division)
	{
		if (stack_aux->index + 1 == (*stack_a)->index
			|| (*stack_b)->index == lstlast(*stack_a)->index + 1)
		{
			i = 1;
			break ;
		}
		stack_aux = stack_aux->next;
	}
	return (i);
}
