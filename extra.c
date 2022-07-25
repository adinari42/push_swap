/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:17:02 by adinari           #+#    #+#             */
/*   Updated: 2022/07/25 03:58:37 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

t_stack	*lst_dup(t_stack *lst)
{
	int j;
	t_stack *new;
	t_stack *head;
	
	j = 0;
	new = NULL;
	head = lst;
	while (lst)
	{
		push(&new, lst->value);
		lst = lst->next;
		j++;
	}
	lst = head;
	return(new);
}
 
 void	lst_index(t_stack *lst, t_stack *sort)
{
	int i;
	t_stack *head_sort;
	t_stack *head_lst;


	i = 0;
	head_sort = sort;
	head_lst = lst;
	while(sort)
	{
		while(lst)
		{
			if (lst->value == sort->value)
				{
					lst->index = i;
					i++;
				}
			lst = lst->next;
		}
		lst = head_lst;
		sort = sort->next;
	}
}

t_stack *sorted_list(t_stack *sort)
{
	t_stack	*lst;
	t_stack *head;
	int		rem;

	rem = 1;
	head = lst_dup(sort);
	lst = head;
	while(rem == 1)
	{
		rem = 0;
		while(lst->next)
		{
			if(lst->value > lst->next->value)
				{
					swap(&lst->value, &lst->next->value);
					rem = 1;
				}
			lst = lst->next;
		}
		lst = head;
	}
	return (lst);
}

void	push_tchunk(t_stack **a, t_stack **b)
{
	int n;

	n = total_indxcount(a) - 3;
	while(total_indxcount(a) > 3)
	{
		if((*a)->index < n)
			pb(a, b);
		else
			ra(a);
	}
}
void	push_tchunk2(t_stack **a, t_stack **b)
{
	int n;
	int i;
	int chunk_size;
	int chunk_border;
	int rotate;

	chunk_border = (total_indxcount(a) - 1) / 5;
	chunk_size = total_indxcount(a) / 5;
	n = total_indxcount(a) - 3;
	rotate = 0;
	
	while(total_indxcount(a) > 3)
	{
		i = 0;
		// printf("\npush_tchunk2\n");
		while (i < chunk_size)
		{
			//sleep(1);
			if((*a)->index < n && (*a)->index <= chunk_border)
				{
					pb(a, b);
					i++;
					if (rotate == 1)
					{
						rb(b);
						rotate = 0;
					}
					else if (rotate == 0)
						rotate = 1;
				}
			else if (total_indxcount(a) > 3)
				ra(a);
			else
				break;
			// if (rotate == 1)
			// {
			// 	rb(b);
			// 	rotate = 0;
			// }
			// else if (rotate == 0)
			// 	rotate = 1;
		}
		chunk_border += chunk_size;
	}
}

void	order_3(t_stack **a)
{
	if((*a)->value < (*a)->next->value && (*a)->value < (*a)->next->next->value && (*a)->next->value > (*a)->next->next->value)
		{
			rra(a);
			sa(a);
		}
	else if((*a)->value > (*a)->next->value && (*a)->value < (*a)->next->next->value && (*a)->next->value < (*a)->next->next->value)
		sa(a);
	else if((*a)->value < (*a)->next->value && (*a)->value > (*a)->next->next->value && (*a)->next->value > (*a)->next->next->value)
		rra(a);
	else if((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		ra(a);
		sa(a);
	}
	else
		ra(a);
}

int	search_index(t_stack **lst, int ix)
{
	t_stack *head;
	int i;

	i = 0;
	head = *lst;
	while(head != NULL)
	{
		if(head->index == ix)
			{
				// lst = head;
				return (i);
			}
		i++;
		head = head->next;
	}
	// lst = head;
	return (i);
}
void	push_back(t_stack **a, t_stack **b)
{
	int n;
	int r;
	t_stack *tmp;
	int max;
	int i;
	int rotation;

	n = total_indxcount(b) - 1;
	max = n;
	// printf("\npushback starts here! \n");
	// printf("\n-----------------------------\n\nA-> ");
	// printer(*a);
	// printf("B-> ");
	// printer(*b);
	//j = 0;
	while((*b))
	{
		// printf("\n[%d]~%d->%d\n", (*b)->value, (*b)->index, n);
		tmp = (*b)->next;
		n = total_indxcount(b);
		r = total_indxcount(b) / 2;
		i = 1;
		rotation = 0;
		lst_index((*b), sorted_list(*b));
  		while (tmp != NULL)
		{
			if (tmp->index == n - 1)
				{
					rotation = i;
					//break;
				}
			i++;
			tmp = tmp->next;
		}
		i = 0;
		if((*b)->index == n - 1)
		{
			pa(b, a);
			//n--;
		}
		else if (rotation > r + 1)//(j > r)
		{
			while (i++ < n - rotation)
				rrb(b);
			//while ((*b)->index != n - 1)
			pa(b, a);
		}
		else
		{
			while (i++ < rotation)
				rb(b);
			//while ((*b)->index != n - 1)
			pa(b, a);
		}
	}
}


void	push_chunks(t_stack *a, t_stack *b)
{

}

