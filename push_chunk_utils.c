/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:37:07 by adinari           #+#    #+#             */
/*   Updated: 2022/08/14 23:54:06 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_pushrotate(t_stack **a, t_stack **b, int chunk_s, int chunk_b)
{
	int		n;
	int		i;

	i = 0;
	n = total_indxcount(a) - 3;
	while (i < chunk_s && total_indxcount(a) > 3)
	{
		if ((*a)->index < n && (*a)->index <= chunk_b)
		{
			i++;
			pushrotate(a, b);
		}
		else if (total_indxcount(a) > 3)
			rotate_direction(a, chunk_b);
		else
			break ;
	}
}

void	pushrotate(t_stack **a, t_stack **b)
{
	static int	rotate = 0;

	pb(a, b);
	if (rotate == 1)
	{
		rb(b, "print");
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
		ra(a, "print");
	else
		rra(a, "print");
}

int	first_occurance(t_stack **a, int chunk_border)
{
	int		first;
	int		i;
	t_stack	*tmp;

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
	int		last;
	int		i;
	t_stack	*tmp;

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
