/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:28:27 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 14:52:34 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*pop currently unused*/
/*
int	pop(t_stack *pop_stack)
{
	if (pop_stack == NULL)
		return (0);
	int	result = pop_stack->value;
	t_stack *tmp = pop_stack; //change this for possible norm error
	pop_stack = pop_stack->next;
	free(tmp);
	return (result);
}*/
/*prints current state of linked list*/

void	printer(t_stack *ab)
{
	t_stack *aa;

	aa = ab;
	if (aa == NULL)
	{
		printf("\n");
		return ;
	}
	while (aa != NULL)
	{
		// printf("[value]->[%d][%d]  ", aa->value, aa->index);
		//printf("[%d]~%d  ", aa->value, aa->index);
		printf(" [%d]~%d ", aa->value, aa->index);
		aa = aa->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	int	i;
	int p;

	i = 1;
	p = 0;

	if (2 > argc)
		return (0);
	while (i < argc)
	{
		if (fill_ll(*(argv + i), &a)) {
			write(1, "Error", 5);
			return 1;
		}
	 	i++;
	}
	int h = total_indxcount(&a);
	// printf("A-> ");
	// printer(a);
	// printf("B-> ");
	// printer(b);
	if (dup_check(&a))
		return (1);	
	if (sort_check(&a))
		return (1);

	lst_index(a, sorted_list(a));
	push_chunk(&a, &b);
	
	// printf("\n-------------post push chunks----------------\n\nA-> ");
	// printer(a);
	// printf("B-> ");
	// printer(b);
	
	order_3(&a);

	// printf("\n-------------post order 3---------------\n\nA-> ");
	// printer(a);
	// printf("B-> ");
	// printer(b);
	
	push_back(&a, &b);

	// printf("\n-------------final result----------------\n\nA-> ");
	// printer(a);
	// printf("B-> ");
	// printer(b);
}
