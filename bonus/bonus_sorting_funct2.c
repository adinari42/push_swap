/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sorting_funct2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:12:20 by adinari           #+#    #+#             */
/*   Updated: 2022/08/13 00:41:22 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
/*
//make copy of b in temp
//remove top of b by giving it the adress of the next second node
//temp becomes top of a by addressing next to a
//a takes shape/structure of temp llist
*/
int	silent_pa(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if ((*b) == NULL)
		return (0);
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	return (0);
}

int	silent_sa(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if ((*a) == NULL)
		return (0);
	if (total_indxcount(a) < 2)
		return (0);
	temp1 = *a;
	*a = (*a)->next;
	temp2 = *a;
	*a = (*a)->next;
	temp1->next = *a;
	temp2->next = temp1;
	*a = temp2;
	return (0);
}

int	silent_ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	if ((*a) == NULL)
		return (0);
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
	return (0);
}

//checking for the end
//free last node
//set next to null to make current node as last node
int	silent_rra(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if ((*a) == NULL)
		return (0);
	temp1 = ft_lstlast(*a);
	temp2 = gener_node(temp1->value);
	temp1 = *a;
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
	ft_lstadd_back(&temp2, *a);
	*a = temp2;
	return (0);
}

int	silent_rr(t_stack **a, t_stack **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
		silent_ra(a);
	else if ((*a) == NULL || (*a)->next == NULL)
		silent_rb(b);
	else
	{
		silent_ra(a);
		silent_rb(b);
	}
	return (0);
}
