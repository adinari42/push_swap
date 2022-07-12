/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:45:11 by adinari           #+#    #+#             */
/*   Updated: 2022/07/10 20:59:58 by adinari          ###   ########.fr       */
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
} 				t_stack;

int	ft_isdigit(int c);

int	ft_atoi(const char *str);

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
/*pushswap.c*/
int	push(t_stack **thestack, int thevalue);
t_stack	*gener_node(int thevalue);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
/*sorting*/
void	sort_alg(t_stack **a, t_stack **b);
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
char			**ft_split(char const *s, char c);
void		free_all(char **words, int n);
int		str_fill(char **s1, const char *s, char c);
size_t	str_radius(const char *s, char c);
int		str_count(char const *s, char c);

#endif