/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:53:55 by adinari           #+#    #+#             */
/*   Updated: 2022/08/10 07:05:58 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

// int	phase1_check(t_stack **a, t_stack **b, char *buffer)
// {
// 	if (!ft_strncmp(buffer, "rb\n", 3))
// 		silent_rb(b);
// 	else if (!ft_strncmp(buffer, "ra\n", 3))
// 		silent_ra(a);
// 	else if (!ft_strncmp(buffer, "rrb\n", 4))
// 		silent_rrb(b);
// 	else if (!ft_strncmp(buffer, "rra\n", 4))
// 		silent_rra(a);
// 	else if (!ft_strncmp(buffer, "rr\n", 3))
// 		silent_rr(a, b);
// 	else if (!ft_strncmp(buffer, "rrr\n", 4))
// 		silent_rrr(a, b);
// 	else
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	return (0);
// }

// int	phase2_check(t_stack **a, t_stack **b, char *buffer)
// {
// 	if (!ft_strncmp(buffer, "sb\n", 3))
// 		silent_sb(b);
// 	else if (!ft_strncmp(buffer, "sa\n", 3))
// 		silent_sa(a);
// 	else if (!ft_strncmp(buffer, "ss\n", 3))
// 		silent_ss(a, b);
// 	else if (!ft_strncmp(buffer, "pb\n", 3))
// 		silent_pb(a, b);
// 	else if (!ft_strncmp(buffer, "pa\n", 3))
// 		silent_pa(a, b);
// 	else
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	return (0);
// }

// int	phase_setup(t_stack **a, t_stack **b, char *buffer)
// {
// 	if (buffer[0] == 'r')
// 	{
// 		if (phase1_check(a, b, buffer))
// 			return (1);
// 	}
// 	else if (buffer[0] == 's' || buffer[0] == 'p')
// 	{
// 		if(phase2_check(a, b, buffer))
// 			return (1);
// 	}
// 	else
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	return (0);
// }

// int	check_buffer(t_stack *a, t_stack *b)
// {
// 	char	*buffer;

// 	while (1)
// 	{
// 		buffer = get_next_line(0);
// 		if (!buffer)
// 			break ;
// 		if (phase_setup(&a, &b, buffer))
// 		{
// 			free_ll(a);
// 			free(buffer);
// 			return (1);
// 		}
// 		free(buffer);
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		i;

// 	b = NULL;
// 	i = 1;
// 	if (3 > argc)
// 		return (0);
// 	while (i < argc)
// 	{
// 		if (fill_ll(*(argv + i), &a))
// 		{
// 			write(2, "Error", 5);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	printer(a);
// 	if (dup_check(&a))
// 		return (1);
// 	if (check_buffer(a, b))
// 		return (0);
// 	if (sort_check(&a) && b == NULL)
// 		write (1, "OK", 2);
// 	else
// 		write(1, "KO", 2);
// 	free_ll(a);
// 	// system("leaks checker");
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*buffer;

	b = NULL;
	i = 1;
	if (2 > argc)
		return (0);
	while (i < argc)
	{
		if (fill_ll(*(argv + i), &a))
		{
			write(2, "Error", 5);
			return (1);
		}
		i++;
	}
	printer(a);
	if (dup_check(&a))
		return (1);
	while (1)
	{
		buffer = get_next_line(0);
		if (buffer == NULL)
			break;
		if (!ft_strncmp(buffer, "sb\n", 3))
			silent_sb(&b);
		else if (!ft_strncmp(buffer, "sa\n", 3))
			silent_sa(&a);
		else if (!ft_strncmp(buffer, "rb\n", 3))
			silent_rb(&b);
		else if (!ft_strncmp(buffer, "ra\n", 3))
			silent_ra(&a);
		else if (!ft_strncmp(buffer, "rrb\n", 4))
			silent_rrb(&b);
		else if (!ft_strncmp(buffer, "rra\n", 4))
			silent_rra(&a);
		else if (!ft_strncmp(buffer, "ss\n", 3))
			silent_ss(&a, &b);
		else if (!ft_strncmp(buffer, "rr\n", 3))
			silent_rr(&a, &b);
		else if (!ft_strncmp(buffer, "rrr\n", 4))
			silent_rrr(&a, &b);
		else if (!ft_strncmp(buffer, "pb\n", 3))
			silent_pb(&a, &b);
		else if (!ft_strncmp(buffer, "pa\n", 3))
			silent_pa(&a, &b);
		else
		{
			free(buffer);
			free_ll(a);
			write(2, "Error\n", 6);
			// system("leaks checker");
			return (0);
		}
		free(buffer);
	}
	write(1, "xd\n", 3);
	if (sort_check(&a) && b == NULL)
		write (1, "OK", 2);
	else
		write(1, "KO", 2);
	free_ll(a);
	// system("leaks checker");
	return (0);
}
