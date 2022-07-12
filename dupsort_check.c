/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupsort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:41 by adinari           #+#    #+#             */
/*   Updated: 2022/07/12 21:22:41 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp1;

	tmp = *a;
	tmp1 = tmp->next;
	printf("dupcheck1\n");
	while (tmp->next != NULL)
	{
		
		printf("dupcheck1\n");
		while (tmp1 != NULL)
		{
			printf("dupcheck2: tmp = %d , tmp1 = %d\n", tmp->value, tmp1->value);
			if (tmp->value == tmp1->value)
			{
				printf("error here : tmp = %d , tmp1 = %d\n", tmp->value, tmp1->value);
				return (write(1, "dupcheck error\n", 15));
			}
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
	printf("sortcheck1\n");
	while (tmp->next != NULL)
	{
		
		printf("sortcheck2: tmp = %d , tmp1 = %d\n", tmp->value, tmp1->value);
		if (tmp->value > tmp1->value)
			{
				printf("not sorted\n");
				return (0);
			}
		tmp = tmp->next;
		tmp1 = tmp->next;
	}
	return (printf("sorted"));
}

int	fill_ll(char *argv, t_stack **a)
{
	//int i;
	int j;
	char **split_int;

	
	j = 0;
	printf("fillcheck1\n");
	split_int = ft_split(argv, 32);
	printf("\nafter split\n");
	while (*(split_int + j) != NULL)
	{
		printf("split + j : %s , adress %d\n", *(split_int + j), j);
		push(a, ft_atoi(*(split_int + j)));
		printf("\npushed arg\n");
		printf("A-> ");
		printer(*a);
		j++;
	}
	return (0);
}