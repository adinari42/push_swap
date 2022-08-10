/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:09:13 by adinari           #+#    #+#             */
/*   Updated: 2022/08/10 07:08:22 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*push argument value as a new node on top of stack a*/
int	push(t_stack **thestack, int thevalue)
{
	t_stack	*newnode;
	t_stack	*temp;

	// temp = NULL;
	if (thestack == NULL)
		return (0);
	newnode = malloc(sizeof(t_stack));
	if (newnode == NULL)
	{
		write(1, "Error\n", 6);
		// free(newnode);
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
