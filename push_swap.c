/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:45:39 by pramos            #+#    #+#             */
/*   Updated: 2024/02/12 11:45:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*stack_aux;

	while (stack != NULL)
	{
		stack_aux = stack;
		stack = stack->next;
		free(stack_aux);
	}
	stack = NULL;
}

void	ft_free(char **matriz, int i)
{
	while (i-- > 0)
		free(matriz[i]);
	free(matriz);
}

void	ft_inistack(int argc, char **argv, t_stack **stack_a)
{
	char	**spl_arr;
	int		i;
	int		j;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			j = 0;
			spl_arr = ft_split(argv[i], ' ');
			while (spl_arr[j])
			{
				lstadd_back(stack_a, lstnew(ft_atoi(spl_arr[j]), 0));
				j++;
			}
			ft_free(spl_arr, j);
			i++;
		}
	}
}

void	leaks()
{
	system("leaks -q push_swap");
}

void	print_stack(t_stack *stack_a)
{
	printf("\n");
	printf("stack_a\n");
	while (stack_a)
	{
		printf("num:%d\n", stack_a->content);
		printf("index:%d\n", stack_a->index);
		stack_a = stack_a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (write(1, "Error\n", 6));
	ft_inistack(argc, argv, &stack_a);
	if (!check_errors(argv, stack_a))
		return (write(1, "Error\n", 6));
	init_algorithm(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
