/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 push_swap.h										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/06 15:17:06 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 17:27:27 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				i_stack;
	int				i_value;
	int				med;
	int				cheap;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

void	sort_to_a(t_stack **a, t_stack **b);
void	sort_to_b(t_stack **a, t_stack **b);

t_stack	*find_min(t_stack **a);
t_stack	*find_cheapest(t_stack *stack);

void	push(t_stack **dest, t_stack **src, char c);
void	reverse_rotate(t_stack **stack, char c);
void	rr_rotate(t_stack **a, t_stack **b);
void	rotate(t_stack **stack, char c);
void	r_rotate(t_stack **a, t_stack **b);
void	swap(t_stack **stack, char c);
void	move_top_a(t_stack *cheapest, t_stack **a, t_stack **b);
void	move_top_b(t_stack *cheapest, t_stack **b, t_stack **a);

int		put_cheap_a(t_stack *tmp, t_stack *target, t_stack **a, t_stack **b);
int		put_cheap_b(t_stack *tmp, t_stack *target, t_stack **b, t_stack **a);
int		s_issort(t_stack *a);

void	put_everything_a(t_stack **a, t_stack **b);
void	put_everything_b(t_stack **a, t_stack **b);
void	in_value(t_stack **stack_ab);
void	in_stack(t_stack **stack_ab);
void	put_index(t_stack **stack);
void	put_stack(t_stack **a, char **av);
void	put_target_a(t_stack *tmp, t_stack **a);
void	put_target_b(t_stack *tmp, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);

int		ft_atoi(char *str);
int		ft_check(int ac, char **av);
int		check_m(char *str, int s);

char	**ft_atoa(char **str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(int ac, char **av);
char	*ft_substr(char *s, unsigned int start, size_t len);

int		ft_strlen(char *str);
int		stack_node(t_stack *a);

void	free_str1(char **str);
void	free_stack(t_stack **a, t_stack **b);
void	ft_putendl_fd(char *s, int fd);

#endif