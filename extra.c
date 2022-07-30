/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:17:02 by adinari           #+#    #+#             */
/*   Updated: 2022/07/30 03:05:07 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

t_stack	*lst_dup(t_stack *lst)
{
	int		j;
	t_stack	*new;
	t_stack	*head;

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
	return (new);
}

void	lst_index(t_stack *lst, t_stack *sort)
{
	int		i;
	t_stack	*head_sort;
	t_stack	*head_lst;

	i = 0;
	head_sort = sort;
	head_lst = lst;
	while (sort)
	{
		while (lst)
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

t_stack	*sorted_list(t_stack *sort)
{
	t_stack	*lst;
	t_stack	*head;
	int		rem;

	rem = 1;
	head = lst_dup(sort);
	lst = head;
	while (rem == 1)
	{
		rem = 0;
		while (lst->next)
		{
			if (lst->value > lst->next->value)
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
/*
int	first_occurance(tmp **a, int chunk_border)
{
	int	first;

	tmp = *a;
	if (direction == 1)
	{
		i = 0;
		while (tmp != NULL)
		{
			if (tmp->index <= chunk_border)
			{
				first = i;
				break ;
			}
			i++;
			tmp = tmp->next;
		}
	}
	return (first);
}

int	last_occurance(tmp **a, int chunk_border)
{
	int	last;

	tmp = *a;
	if (direction == 1)
	{
		i = 0;
		while (tmp != NULL)
		{
			if (tmp->index <= chunk_border)
			{
				last = i;
				break ;
			}
			i++;
			tmp = tmp->next;
		}
	}
	return (last);
}
*/
void	rotate_direction(t_stack **a, int chunk_border)
{
	int		i;//
	int		first;
	int		last;
	int		count;

	tmp = *a;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->index <= chunk_border)
		{
			first = i;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	//first = first_occurance(a, chunk_border);//
	i = total_indxcount(a);
	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->index <= chunk_border)
		{
			last = i;
			break ;
		}
		i--;
		tmp = tmp->next;
	}
	if (first <= last)
		ra(a);
	else
		rra(a);
}

int	measure_random(t_stack **a)
{
	t_stack	*tmp;
	int		scale;

	scale = 0;
	tmp = (*a);
	while (tmp->next)
	{
		scale += tmp->value - tmp->next->value;
		tmp = tmp->next;
	}
	return (scale);
}
int	chunk_sizer(t_stack **a)
{	
	t_stack	*tmp;
	int		scale;
	int		i;

	i = 0;
	scale = 0;
	tmp = (*a);
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	scale += (i / 100) * 5;
	scale -= scale / 20;
	return (scale - 5);
}

int	chunk_number(t_stack *a)
{
	int	n;

	n = total_indxcount(&a);
	if (n <= 10)
		return (2);
	else if (n > 10 && n <= 100)
		return (5);
	else if (n > 100)
		return (chunk_sizer(&a));
	else
		return (1);
}

void	push_tchunk2(t_stack **a, t_stack **b)
{
	int	n;
	int	i;
	int	chunk_size;
	int	chunk_border;
	int	rotate;

	chunk_border = (total_indxcount(a) - 1) / chunk_number(*a);
	chunk_size = total_indxcount(a) / chunk_number(*a);
	rotate = 0;
	while (total_indxcount(a) > 3)
	{
		n = total_indxcount(a) - 3;
		i = 0;
		lst_index(*a, sorted_list(*a));
		while (i < chunk_size && total_indxcount(a) > 3)
		{
			
			if ((*a)->index < n && (*a)->index <= chunk_border)
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
				rotate_direction(a, chunk_border);//ra(a);
			else
				break;
		}
	}
}

void	order_3(t_stack **a)
{
	if ((*a)->value < (*a)->next->value && (*a)->value < (*a)->next->next->value && (*a)->next->value > (*a)->next->next->value)
		{
			rra(a);
			sa(a);
		}
	else if ((*a)->value > (*a)->next->value && (*a)->value < (*a)->next->next->value && (*a)->next->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value < (*a)->next->value && (*a)->value > (*a)->next->next->value && (*a)->next->value > (*a)->next->next->value)
		rra(a);
	else if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		ra(a);
		sa(a);
	}
	else
		ra(a);
}

int	search_index(t_stack **lst, int ix)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = *lst;
	while (head != NULL)
	{
		if (head->index == ix)
			return (i);
		i++;
		head = head->next;
	}
	return (i);
}

void	push_back(t_stack **a, t_stack **b)
{
	int		n;
	int		r;
	t_stack	*tmp;
	int		i;
	int		rotation;

	while ((*b))
	{
		tmp = (*b)->next;
		n = total_indxcount(b);
		r = total_indxcount(b) / 2;
		i = 1;
		rotation = 0;
		lst_index((*b), sorted_list(*b));
  		while (tmp != NULL)
		{
			if (tmp->index == n - 1)
				rotation = i;
			i++;
			tmp = tmp->next;
		}
		i = 0;
		if((*b)->index == n - 1)
			pa(b, a);
		else if (rotation > r + 1)
		{
			while (i++ < n - rotation)
				rrb(b);
			pa(b, a);
		}
		else
		{
			while (i++ < rotation)
				rb(b);
			pa(b, a);
		}
	}
}
