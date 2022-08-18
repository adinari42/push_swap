/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:28:27 by adinari           #+#    #+#             */
/*   Updated: 2022/08/17 03:01:29 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printer(t_stack *ab)
{
	t_stack	*aa;

	aa = ab;
	if (aa == NULL)
	{
		printf("\n");
		return ;
	}
	while (aa != NULL)
	{
		printf(" [%d]~%d ", aa->value, aa->index);
		aa = aa->next;
	}
	printf("\n");
}

//initializes linked list a with parameters argv,
//prints error in case of failure
//returns 1 in case of duplicates
int	init_junk(int argc, char **argv, t_stack **a)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (fill_ll(*(argv + i), a))
			return (write(2, "Error\n", 6));
	if (argc < 2)
		return (2);
	if (total_indxcount(a) < 2)
		return (2);
	if (dup_check(a))
		return (write(2, "Error\n", 6));
	return (0);
}

/*
sorted_list : create a copy of stack a that is sorted
lst_index : use the copy as reference to index the original stack
push_chunk : push chunks from a to b except for biggest 3 digits
order : orders remaining digits
push_back : pushes nodes back from b to a , from biggest to smallest value
*/
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
	i = 0;
	if (init_junk(argc, argv, &a) != 0)
		return (1);
	if (total_indxcount(&a) == 2)
	{
		order_2(&a);
		return (0);
	}
	if (sort_check(&a))
		return (1);
	push_swap(a, b);
	return (0);
}
