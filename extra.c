/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:17:02 by adinari           #+#    #+#             */
/*   Updated: 2022/08/03 21:17:40 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_3(t_stack **a)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;

	tmp1 = (*a)->value;
	tmp2 = (*a)->next->value;
	tmp3 = (*a)->next->next->value;
	if (tmp1 < tmp2 && tmp1 < tmp3 && tmp2 > tmp3)
	{
		rra(a, "print");
		sa(a, "print");
	}
	else if (tmp1 > tmp2 && tmp1 < tmp3 && tmp2 < tmp3)
		sa(a, "print");
	else if (tmp1 < tmp2 && tmp1 > tmp3 && tmp2 > tmp3)
		rra(a, "print");
	else if (tmp1 > tmp2 && tmp1 > tmp3 && tmp2 > tmp3)
	{
		ra(a, "print");
		sa(a, "print");
	}
	else if (tmp1 > tmp2 && tmp1 > tmp3 && tmp2 < tmp3)
		ra(a, "print");
	else
		return ;
}

int	total_indxcount(t_stack **a)
{
	t_stack	*tmp;
	int		j;

	j = 1;
	tmp = *a;
	while (tmp->next != NULL)
	{
		j++;
		tmp = tmp->next;
	}
	return (j);
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
	return (scale - 6);
}
