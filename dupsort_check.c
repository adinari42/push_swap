/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupsort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:41 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 14:50:01 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *a;
	tmp1 = tmp->next;
	while (tmp->next != NULL)
	{
		while (tmp1 != NULL)
		{
			if (tmp->value == tmp1->value)
				ft_error(1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	return (0);
}

int	sort_check(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp1;

	tmp = *a;
	tmp1 = tmp->next;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp1->value)
			return (0);
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	exit (0);
}

int	fill_ll(char *argv, t_stack **a)
{
	int		j;
	char	**split_int;
	int		error;
	long	n;
	
	j = 0;
	split_int = ft_split(argv, 32);
	if (*(split_int + j) == NULL)
		return (1);
	while (*(split_int + j) != NULL)
	{
		int error = ft_atoi(*(split_int + j), &n);
		if (error)
			return (1);
		push(a, n);
		j++;
	}
	return (0);
}
