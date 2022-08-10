/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:48:01 by adinari           #+#    #+#             */
/*   Updated: 2022/08/03 21:18:11 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack **a, t_stack **b)
{
	int		n;
	int		i;
	int		rotation;

	while ((*b))
	{
		n = total_indxcount(b);
		lst_index((*b), sorted_list(*b));
		rotation = update_rotation(b);
		i = 0;
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
}

int	update_rotation(t_stack **b)
{
	int	i;
	int	rotation;
	int	n;

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
