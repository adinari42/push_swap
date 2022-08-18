/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:53:55 by adinari           #+#    #+#             */
/*   Updated: 2022/08/15 02:13:16 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	operations(char *buffer, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(buffer, "sb\n", 3))
		return (silent_sb(b));
	else if (!ft_strncmp(buffer, "sa\n", 3))
		return (silent_sa(a));
	else if (!ft_strncmp(buffer, "rb\n", 3))
		return (silent_rb(b));
	else if (!ft_strncmp(buffer, "ra\n", 3))
		return (silent_ra(a));
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		return (silent_rrb(b));
	else if (!ft_strncmp(buffer, "rra\n", 4))
		return (silent_rra(a));
	else if (!ft_strncmp(buffer, "ss\n", 3))
		return (silent_ss(a, b));
	else if (!ft_strncmp(buffer, "rr\n", 3))
		return (silent_rr(a, b));
	else if (!ft_strncmp(buffer, "rrr\n", 4))
		return (silent_rrr(a, b));
	else if (!ft_strncmp(buffer, "pb\n", 3))
		return (silent_pb(a, b));
	else if (!ft_strncmp(buffer, "pa\n", 3))
		return (silent_pa(b, a));
	else
		return (1);
}

//in case of failure, free buffer and a, print error and return.
int	free_junk(char **buffer, t_stack **a, t_stack **b)
{
	free(*buffer);
	free_ll(*a);
	write(2, "Error\n", 6);
	return (1);
}

//initializes linked list a with parameters argv,
//prints error in case of failure
//returns 1 in case of duplicates
int	init_junk(int argc, char **argv, t_stack **a)
{
	int	i;

	i = 0;
	if (2 > argc)
		return (2);
	while (++i < argc)
		if (fill_ll(*(argv + i), a))
			return (write(2, "Error\n", 6));
	if (dup_check(a))
		return (write(2, "Error\n", 6));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*buffer;

	b = NULL;
	if (init_junk(argc, argv, &a) != 0)
		return (1);
	while (1)
	{
		buffer = get_next_line(0);
		if (buffer == NULL)
			break ;
		if (operations(buffer, &a, &b) != 0)
			return (free_junk(&buffer, &a, &b));
		free(buffer);
	}
	if (sort_check(&a) && b == NULL)
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_ll(a);
	return (0);
}
