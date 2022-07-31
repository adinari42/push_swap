/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:13:17 by adinari           #+#    #+#             */
/*   Updated: 2022/07/31 14:43:18 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*skips spaces using line 28 loop, considers '-' sign, increments i
check individual char of str is number (ft_isdigit) 
check ascii of characters and does -48 for conversion (- '0')
multiplies by 10 to push the current integer to left
checks if current val is under or above max long min long int
*/

void ft_error(int i)
{
	write(2, "Error\n", 6);
	i++;
	exit (1);
}

int	minmax_intcheck(const char *str, int sign, long *result)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		*result = (*result * 10) + (str[i++] - '0');
		if (*result > 2147483647 && sign == 1)
			return (0);
		if (*result > 2147483648 && sign == -1)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str, long *result)
{
	int		sign;
	int		i;
	int		t;

	*result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
			return (-1);
	t = minmax_intcheck(str, sign, result);
	if (!t)
		return (-1);
	if (!ft_isdigit(str[i]) && str[i])
	{
		return (1);
		ft_error(i);
	}
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
