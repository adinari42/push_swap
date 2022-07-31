/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:58:51 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 12:05:07 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	lst_index(t_stack *lst, t_stack *sort)
{
	int		j;
	t_stack	*head_sort;
	t_stack	*head_lst;

	j = 0;
	head_sort = sort;
	head_lst = lst;
	while (sort)
	{
		while (lst)
		{
			if (lst->value == sort->value)
			{
				lst->index = j;
				j++;
			}
			lst = lst->next;
		}
		lst = head_lst;
		sort = sort->next;
	}
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

void	swap(int *a, int *b)
{
	int	swp;

	swp = *a;
	*a = *b;
	*b = swp;
}
