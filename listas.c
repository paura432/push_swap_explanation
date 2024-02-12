/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:26:09 by pramos            #+#    #+#             */
/*   Updated: 2023/06/05 18:23:56 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*new1;

	if (*lst)
	{
		new1 = lstlast(*lst);
		new1->next = new;
		new->next = NULL;
	}
	else
	{
		*lst = new;
		(*lst)->next = NULL;
	}
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*new1;

	new1 = *lst;
	*lst = new;
	(*lst)->next = new1;
}

t_stack	*lstnew(int content, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->index = index;
	new->content = content;
	new->next = NULL;
	return (new);
}

int	lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
