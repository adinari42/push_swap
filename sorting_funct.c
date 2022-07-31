/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:59:30 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 12:37:34 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
//make copy of a in temp
//remove top of a by giving it the adress of the next second node
//temp becomes top of b by addressing next to b
//b takes shape/structure of temp llist
*/
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);

}

void	sb(t_stack **b)
{
	t_stack	*temp1;
	t_stack *temp2;

	temp1 = *b;
	*b = (*b)->next;
	temp2 = *b;
	*b = (*b)->next;
	temp1->next = *b;
	temp2->next = temp1;
	*b = temp2;
	write(1, "sb\n", 3);
}
void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*temp1;
	t_stack *temp2;

	temp1 = (*b)->next;
	(*b)->next = NULL;
	if (temp1 == NULL)
		temp1 = *b;
	else
	{
		temp2 = temp1;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = *b;
		*b = temp1;
	}
	write(1, "rb\n", 3);
}
//checking last node
//free before last node
//set current node next to null to make it last node
void	rrb(t_stack **b)
{
	t_stack	*temp1;
	t_stack *temp2;

	if ((*b)->next == NULL)
		return ;
	temp1 = ft_lstlast(*b);
	temp2 = gener_node(temp1->value);
	temp1 = *b;
	while(temp1->next != NULL)
	{	
		if (temp1->next->next == NULL)
		{
			free(temp1->next);
			temp1->next = NULL;
		}
		else
			temp1 = temp1->next;
	}
	ft_lstadd_back(&temp2, *b);
	*b = temp2;
	write(1, "rrb\n", 4);
}
