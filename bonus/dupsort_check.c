/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupsort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:41 by adinari           #+#    #+#             */
/*   Updated: 2022/08/14 23:53:26 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
				return (1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	return (0);
}

int	sort_check(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *a;
	tmp1 = tmp->next;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp1->value)
			return (0);
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	return (1);
}

void	free_ll(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp;

	tmp = stack;
	tmp1 = NULL;
	while (tmp)
	{
		tmp1 = tmp;
		tmp = tmp->next;
		free(tmp1);
	}
	stack = NULL;
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	fill_ll(char *argv, t_stack **a)
{
	int		j;
	char	**split_int;
	int		error;
	long	n;
	t_stack	*tmp;

	j = 0;
	split_int = ft_split(argv, 32);
	if (*(split_int + j) == NULL)
		return (1);
	while (*(split_int + j) != NULL)
	{
		error = ft_atoi(*(split_int + j), &n);
		if (error)
			return (1);
		push(a, n);
		j++;
	}
	tmp = ft_lstlast(*a);
	free(tmp->next);
	tmp->next = NULL;
	free_all(split_int, j);
	return (0);
}
