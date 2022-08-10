/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adinari <adinari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:01:20 by adinari           #+#    #+#             */
/*   Updated: 2022/08/10 06:19:31 by adinari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define BUFFER_SIZE 10

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_stack
{
	int 			value;
	struct s_stack 	*next;
	int				index;
} 				t_stack;

t_stack *tmp;

/*check_functions*/
int		minmax_intcheck(const char *str, int *sign, long *result);
int		ft_atoi(char *str, long *result);
int		ft_isdigit(int c);
void	silent_rrr(t_stack **a, t_stack **b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/*dupsort_check*/
int		fill_ll(char *argv, t_stack **a);
int		dup_check(t_stack **a);
int		sort_check(t_stack **a);
void	free_ll(t_stack *stack);
int		ft_lstsize(t_stack *lst);
/*checker.c*/
char	*gener_line(char *buffer);
int		check_buffer(t_stack *a, t_stack *b);
int		phase1_check(t_stack **a, t_stack **b, char *buffer);
int		phase2_check(t_stack **a, t_stack **b, char *buffer);
int		phase_setup(t_stack **a, t_stack **b, char *buffer);
/*sorting_funct.c*/
void	silent_pb(t_stack **a, t_stack **b);
void	silent_sb(t_stack **b);
void	silent_ss(t_stack **a, t_stack **b);
void	silent_rb(t_stack **b);
void	silent_rrb(t_stack **b);
/*sorting_funct2.c*/
void	silent_pa(t_stack **b, t_stack **a);
void	silent_sa(t_stack **a);
void	silent_ra(t_stack **a);
void	silent_rra(t_stack **a);
void	silent_rr(t_stack **a, t_stack **b);
/*split.c*/
char	**ft_split(char const *s, char c);
void	free_all(char **words, int n);
int		str_fill(char **s1, const char *s, char c);
size_t	str_radius(const char *s, char c);
int		str_count(char const *s, char c);

/*get next line utils .c*/
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *string, int n);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
/*get_next_line*/
char	*new_bufferstart(char *buffer);
char	*gener_line(char *buffer);
char	*init_buffer(int fd, char *orig_buffer);
char	*get_next_line(int fd);
/*ll_ctrl.c*/
t_stack	*gener_node(int thevalue);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		push(t_stack **thestack, int thevalue);
/*utils*/
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		total_indxcount(t_stack **a);

#endif
