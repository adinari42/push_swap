/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:13:17 by adinari           #+#    #+#             */
/*   Updated: 2022/08/11 17:56:58 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
/*skips spaces using line 28 loop, considers '-' sign, increments i
check individual char of str is number (ft_isdigit) 
check ascii of characters and does -48 for conversion (- '0')
multiplies by 10 to push the current integer to left
checks if current val is under or above max long min long int
*/
int	minmax_intcheck(const char *str, int *sign, long *result)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		*result = (*result * 10) + (str[i++] - '0');
		if (*result > 2147483647 && *sign == 1)
			return (0);
		if (*result > 2147483648 && *sign == -1)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_atoi(char *str, long *result)
{
	int		sign;
	int		i;
	int		t;

	*result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		str++;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	t = minmax_intcheck(str, &sign, result);
	if (!t)
		return (-1);
	*result *= sign;
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9' )
		return (c);
	else
		return (0);
}

int	silent_rrr(t_stack **a, t_stack **b)
{
	if ((*b) == NULL || (*b)->next == NULL)
		silent_rra(a);
	else if ((*a) == NULL || (*a)->next == NULL)
		silent_rrb(b);
	else
	{
		silent_rra(a);
		silent_rrb(b);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (str1[i] != str2[i] || (str1[i] || str2[i]) == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
