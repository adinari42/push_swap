/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:37:07 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 15:59:27 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_stack **a, t_stack **b)
{
	int	i;
	int	chunk_size;
	int	chunk_border;
	int	n;

	chunk_border = (total_indxcount(a) - 1) / chunk_number(*a);
	chunk_size = total_indxcount(a) / chunk_number(*a);
	while (total_indxcount(a) > 3)
	{
		n = total_indxcount(a) - 3;
		i = 0;
		lst_index(*a, sorted_list(*a));
		while (i < chunk_size && total_indxcount(a) > 3)
		{
			if ((*a)->index < n && (*a)->index <= chunk_border)
			{
				i++;
				pushrotate(a, b);
			}
			else if (total_indxcount(a) > 3)
				rotate_direction(a, chunk_border);
			else
				break ;
		}
	}
}

void	pushrotate(t_stack **a, t_stack **b)
{
	static int	rotate = 0;

	pb(a, b);
	if (rotate == 1)
	{
		rb(b);
		rotate = 0;
	}
	else if (rotate == 0)
		rotate = 1;
}

void	rotate_direction(t_stack **a, int chunk_border)
{
	int		first;
	int		last;

	first = first_occurance(a, chunk_border);
	last = last_occurance(a, chunk_border);
	if (first <= last)
		ra(a);
	else
		rra(a);
}

int	first_occurance(t_stack **a, int chunk_border)
{
	int	first;
	int	i;

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
	return (first);
}

int	last_occurance(t_stack **a, int chunk_border)
{
	int	last;
	int	i;

	tmp = *a;
	i = total_indxcount(a);
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
	return (last);
}
