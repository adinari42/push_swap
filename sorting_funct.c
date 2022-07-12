/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:59:30 by adinari           #+#    #+#             */
/*   Updated: 2022/07/06 01:45:00 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;//make copy of a in temp
	*a = (*a)->next;//remove top of a by giving it the adress of the next second node
	temp->next = *b;//temp becomes top of b by addressing next to b
	*b = temp;//b takes shape/structure of temp llist
	write(1, "pb\n", 3);
	// printer(*a);
	// printer(*b);
	
}

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	temp = *b;//make copy of b in temp
	*b = (*b)->next;//remove top of b by giving it the adress of the next second node
	temp->next = *a;//temp becomes top of a by addressing next to a
	*a = temp;//a takes shape/structure of temp llist
	write(1, "pa\n", 3);
}
void	sa(t_stack **a)
{
	t_stack	*temp1;
	t_stack *temp2;

	temp1 = *a;//make copy of a in temp
	*a = (*a)->next;//remove top of a by giving it the adress of the next second node
	temp2 = *a;
	*a = (*a)->next;
	temp1->next = *a;
	temp2->next = temp1;
	*a = temp2;
	write(1, "sa\n", 3);
}
void	sb(t_stack **b)
{
	t_stack	*temp1;
	t_stack *temp2;

	temp1 = *b;//make copy of b in temp
	*b = (*b)->next;//remove top of b by giving it the adress of the next second node
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
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);

	write(1, "rr\n", 3);
}

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
		if (temp1->next->next == NULL)//checking last node
		{
			free(temp1->next);//free before last node
			temp1->next = NULL;//set current node next to null to make it last node
		}
		else
			temp1 = temp1->next;
	}
	ft_lstadd_back(&temp2, *a);
	*a = temp2;
	write(1, "rra\n", 3);
}
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
		if (temp1->next->next == NULL)//checking last node
		{
			free(temp1->next);//free before last node
			temp1->next = NULL;//set current node next to null to make it last node
		}
		else
			temp1 = temp1->next;
	}
	ft_lstadd_back(&temp2, *b);
	*b = temp2;
	write(1, "rrb\n", 3);
}