/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:14:38 by adinari           #+#    #+#             */
/*   Updated: 2022/07/07 15:42:03 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_indxcount(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = *a;
	
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sort_alg(t_stack **a, t_stack **b)
{
	int	max;
	int	max_index;
	int	i;
	int total_indx;
	t_stack *tmp;
	int op_num = 0;

	/*copy a in tmp, iterate through it, find index of the max value,
	then rotate through original a max_index times and push the max */
	
	max_index = 1;

	while ((*a))
	{	
		max = (*a)->value;
		total_indx = total_indxcount(a);
		printf("total indx : %d \n", total_indx);
		i = 1;
		tmp = *a;
		max = tmp->value;
		tmp = tmp->next;
		max_index = 0;
		while (tmp != NULL)
		{
			if (tmp->value > max)
			{
				max = tmp->value;
				max_index = i;
			}
			i++;
			tmp = tmp->next;
		}
		printf("max int : %d \n", max);
		printf("max int index :%d\n", max_index);
		
		
		i = 0;

		if (max_index == 0)
		{
			pb(a, b);
			printf("A->00 ");
			printer(*a);
			printf("B-> ");
			printer(*b);
			op_num++;
		}
		else if (max_index > total_indx / 2)
		{ 
			while (i++ < total_indx - max_index)
			{
				rra(a);
				op_num++;
			}
			pb(a, b);
			printf("A-> ");
			printer(*a);
			printf("B-> ");
			printer(*b);
			op_num++;
		}
		else
		{
			while (i++ < max_index)
			{
				ra(a);
				op_num++;
			}
			pb(a, b);
			printf("A-> ");
			printer(*a);
			printf("B-> ");
			printer(*b);
			op_num++;
		}
	}
	printf("number of operations = %d \n", op_num);
}