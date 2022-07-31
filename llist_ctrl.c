/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:23:04 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 12:24:04 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
