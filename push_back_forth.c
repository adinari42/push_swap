/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_forth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:48:01 by adinari           #+#    #+#             */
/*   Updated: 2022/08/14 23:53:47 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack **a, t_stack **b)
{
	t_stack	*buffer;

	while ((*b))
	{
		buffer = sorted_list(*b);
		lst_index((*b), buffer);
		free_ll(buffer);
		rotate1(a, b);
	}
}

void	rotate1(t_stack **a, t_stack **b)
{
	int		n;
	int		i;
	int		rotation;

	n = total_indxcount(b);
	i = 0;
	rotation = update_rotation(b);
	if ((*b)->index == n - 1)
		pa(b, a);
	else if (rotation > (total_indxcount(b) / 2) + 1)
	{
		while (i++ < n - rotation)
			rrb(b, "print");
		pa(b, a);
	}
	else
	{
		while (i++ < rotation)
			rb(b, "print");
		pa(b, a);
	}
}

int	update_rotation(t_stack **b)
{
	int		i;
	int		rotation;
	int		n;
	t_stack	*tmp;

	rotation = 0;
	i = 1;
	tmp = (*b)->next;
	n = total_indxcount(b);
	while (tmp != NULL)
	{
		if (tmp->index == n - 1)
			rotation = i;
		i++;
		tmp = tmp->next;
	}
	return (rotation);
}

void	push_chunk(t_stack **a, t_stack **b)
{
	int		chunk_size;
	t_stack	*buffer;
	int		chunk_border;

	chunk_border = (total_indxcount(a) - 1) / chunk_number(*a);
	chunk_size = total_indxcount(a) / chunk_number(*a);
	while (total_indxcount(a) > 3)
	{
		buffer = sorted_list(*a);
		lst_index(*a, buffer);
		free_ll(buffer);
		handle_pushrotate(a, b, chunk_size, chunk_border);
	}
}
