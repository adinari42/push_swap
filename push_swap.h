/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:45:11 by adinari           #+#    #+#             */
/*   Updated: 2022/08/10 10:25:11 by adinari          ###   ########.fr       */
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

/*check_functions.c*/
int		minmax_intcheck(const char *str, int *sign, long *result);
int		ft_atoi(char *str, long *result);
int		ft_isdigit(int c);
void	rrr(t_stack **a, t_stack **b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*dupsort_check.c*/
int		dup_check(t_stack **a);
int		sort_check(t_stack **a);
void	free_ll(t_stack *stack);
int		ft_lstsize(t_stack *lst);
int		fill_ll(char *argv, t_stack **a);
/*ll_ctrl*/
int	push(t_stack **thestack, int thevalue);
t_stack	*gener_node(int thevalue);
t_stack	*ft_lstlast(t_stack *lst);
/*extra.c*/
void	order_3(t_stack **a);
int		total_indxcount(t_stack **a);
int		search_index(t_stack **lst, int ix);
int		chunk_number(t_stack *a);
int		chunk_sizer(t_stack **a);
/*split.c*/
char	**ft_split(char const *s, char c);
void	free_all(char **words, int n);
int		str_fill(char **s1, const char *s, char c);
size_t	str_radius(const char *s, char c);
int		str_count(char const *s, char c);
/*llist_ctrl.c*/
int		push(t_stack **thestack, int thevalue);
t_stack	*gener_node(int thevalue);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
/*push_back_forth.c*/
void	push_back(t_stack **a, t_stack **b);
int		update_rotation(t_stack **b);
void 	rotate1(t_stack **a, t_stack **b);
void	push_chunk(t_stack **a, t_stack **b);
/*push_chunk_utils.c*/
void	pushrotate(t_stack **a, t_stack **b);
void	rotate_direction(t_stack **a, int chunk_border);
int		first_occurance(t_stack **a, int chunk_border);
int		last_occurance(t_stack **a, int chunk_border);
void	handle_pushrotate(t_stack **a, t_stack **b, int chunk_size, int chunk_border);
/*pushswap.c*/
void	push_swap(t_stack *a, t_stack *b);
/*sorted_list.c*/
t_stack	*sorted_list(t_stack *sort);
void	lst_index(t_stack *lst, t_stack *sort);
t_stack	*lst_dup(t_stack *lst);
void	swap(int *a, int *b);
void 	order(t_stack **a);
/*sorting_funct.c*/
void	pb(t_stack **a, t_stack **b);
void	sb(t_stack **b, char *str);
void	ss(t_stack **a, t_stack **b);
void	rb(t_stack **b, char *str);
void	rrb(t_stack **b, char *str);
/*sorting_funct2.c*/
void	pa(t_stack **b, t_stack **a);
void	sa(t_stack **a, char *str);
void	ra(t_stack **a, char *str);
void	rra(t_stack **a, char *str);
void	rr(t_stack **a, t_stack **b);
/*utils.c*/
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	order_2(t_stack **a);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif