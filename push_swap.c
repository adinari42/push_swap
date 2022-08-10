/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:28:27 by adinari           #+#    #+#             */
/*   Updated: 2022/08/10 10:51:13 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printer(t_stack *ab)
// {
// 	t_stack	*aa;

// 	aa = ab;
// 	if (aa == NULL)
// 	{
// 		printf("\n");
// 		return ;
// 	}
// 	while (aa != NULL)
// 	{
// 		printf(" [%d]~%d ", aa->value, aa->index);
// 		aa = aa->next;
// 	}
// 	printf("\n");
// }
void	push_swap(t_stack *a, t_stack *b)
{
	t_stack	*sorted_l;

	sorted_l = sorted_list(a);
	lst_index(a, sorted_l);
	free_ll(sorted_l);
	push_chunk(&a, &b);
	order(&a);
	push_back(&a, &b);
	free_ll(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	b = NULL;
	i = 1;
	if (3 > argc)
		return (0);
	while (i < argc)
	{
		if (fill_ll(*(argv + i), &a))
			return (write(2, "Error", 5));
		i++;
	}
	if (argc == 3)
	{
		order_2(&a);
		return (0);
	}
	if (dup_check(&a))
		return (1);
	if (sort_check(&a))
		return (1);
	push_swap(a, b);
	return (0);
}
