/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sorting_funct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:59:30 by adinari           #+#    #+#             */
/*   Updated: 2022/08/13 00:41:43 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
/*
//make copy of a in temp
//remove top of a by giving it the adress of the next second node
//temp becomes top of b by addressing next to b
//b takes shape/structure of temp llist
*/
int	silent_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if ((*a) == NULL)
		return (0);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	return (0);
}

int	silent_sb(t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if ((*b) == NULL)
		return (0);
	temp1 = *b;
	*b = (*b)->next;
	temp2 = *b;
	*b = (*b)->next;
	temp1->next = *b;
	temp2->next = temp1;
	*b = temp2;
	return (0);
}

int	silent_ss(t_stack **a, t_stack **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
		silent_sa(a);
	else if ((*a) == NULL || (*a)->next == NULL)
		silent_sb(b);
	else
	{
		silent_sa(a);
		silent_sb(b);
	}
	return (0);
}

int	silent_rb(t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if ((*b) == NULL)
		return (0);
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
	return (0);
}

//checking last node
//free before last node
//set current node next to null to make it last node
int	silent_rrb(t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if ((*b) == NULL)
		return (0);
	temp1 = ft_lstlast(*b);
	temp2 = gener_node(temp1->value);
	temp1 = *b;
	while (temp1->next != NULL)
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
	return (0);
}
