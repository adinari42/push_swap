/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:45:11 by adinari           #+#    #+#             */
/*   Updated: 2022/07/30 03:00:43 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int 			value;
	struct s_stack 	*next;
	int				index;
} 				t_stack;

t_stack *tmp;
int		i;

int	ft_isdigit(int c);

int	ft_atoi(const char *str, long *n);

void ft_error(int i);

void	printer(t_stack *ab);
/*sorting_funct.c*/
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rotate(t_stack **a, int flag);
void	rrotate(t_stack **a, int flag);
/*pushswap.c*/
int		push(t_stack **thestack, int thevalue);
t_stack	*gener_node(int thevalue);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
/*sorting*/
int		total_indxcount(t_stack **a);
/*utils.c ==== ft_substr*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/*dupsort_check.c*/
int		fill_ll(char *argv, t_stack **a);
int		dup_check(t_stack **a);
int		sort_check();
/*utils.c*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
/*split.c*/
char	**ft_split(char const *s, char c);
void	free_all(char **words, int n);
int		str_fill(char **s1, const char *s, char c);
size_t	str_radius(const char *s, char c);
int		str_count(char const *s, char c);
/*extra(sorting algorithm)*/
t_stack *sorted_list(t_stack *sort);
void	lst_index(t_stack *lst, t_stack *sort);
void	push_tchunk2(t_stack **a, t_stack **b);
void	push_back(t_stack **a, t_stack **b);
void	order_3(t_stack **a);

#endif