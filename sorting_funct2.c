/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:12:20 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 12:37:10 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
//make copy of b in temp
//remove top of b by giving it the adress of the next second node
//temp becomes top of a by addressing next to a
//a takes shape/structure of temp llist
*/
void	pa(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	sa(t_stack **a)
{
	t_stack	*temp1;
	t_stack *temp2;

	temp1 = *a;
	*a = (*a)->next;
	temp2 = *a;
	*a = (*a)->next;
	temp1->next = *a;
	temp2->next = temp1;
	*a = temp2;
	write(1, "sa\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack *temp2;

	temp = (*a)->next;
	(*a)->next = NULL;
	if (temp == NULL)
		temp = *a;
	else
	{
		temp2 = temp;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = *a;
		*a = temp;
	}
	write(1, "ra\n", 3);
}
//checking for the end
//free last node
//set next to null to make current node as last node
void	rra(t_stack **a)
{
	t_stack	*temp1;
	t_stack *temp2;

	if ((*a)->next == NULL)
		return ;
	temp1 = ft_lstlast(*a);
	temp2 = gener_node(temp1->value);
	temp1 = *a;
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
	ft_lstadd_back(&temp2, *a);
	*a = temp2;
	write(1, "rra\n", 4);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
