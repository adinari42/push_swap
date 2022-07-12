/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:28:27 by adinari           #+#    #+#             */
/*   Updated: 2022/07/12 22:05:09 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*pop currently unused*/
int	pop(t_stack *pop_stack)
{
	if (pop_stack == NULL)
		return (0);
	int	result = pop_stack->value;
	t_stack *tmp = pop_stack; //change this for possible norm error
	pop_stack = pop_stack->next;
	free(tmp);
	return (result);
}

/*push argument value as a new node on top of stack a*/
int	push(t_stack **thestack, int thevalue)
{
	t_stack	*newnode;
	t_stack	*temp;

	temp = NULL;
	newnode = malloc(sizeof(t_stack));
	if (newnode == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	newnode->value = thevalue;
	newnode->next = NULL;
	if (*thestack == NULL)
		*thestack = newnode;
	else
	{
		temp = *thestack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
	return (1);
}
/*generate new ll node with given value*/
t_stack	*gener_node(int thevalue)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = thevalue;
	new_node->next = NULL;
	return (new_node);
}
/*returns last node of the ll*/
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*adds *new node to the back of **lst*/
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
/*adds *new node to the front of **lst*/
void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

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
		printf("[value]->[%d]  ", aa->value);
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
	// int errortest;

	i = 1;
	p = 0;
	// errortest = fill_ll(*argv, &a);
	// *value = ft_atoi(*argv);
	if (2 > argc)
		return (0);
	//if (fill_ll(*argv, &a))
		//return (write(1, "Error\n", 6));
	
	while (i < argc)
	{
		fill_ll(*(argv + i), &a);
	 	i++;
	}
	if (dup_check(&a))
		return (1);	
	if (sort_check(&a))
		return (1);
	sort_alg(&a, &b);

	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	
	/*printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);*/

	/*
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	sb(&b);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	pa(&b, &a);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	sa(&a);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	pb(&a, &b);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	ss(&a, &b);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	ra(&a);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	rb(&b);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	rr(&a, &b);
	printf("A-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	rrb(&b);
	printf("\nA-> ");
	printer(a);
	printf("B-> ");
	printer(b);
	rra(&a);
	printf("\nA-> ");
	printer(a);
	printf("B-> ");
	printer(b);
*/
}
