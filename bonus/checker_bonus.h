/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:13:29 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 11:53:19 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int	ft_check(int ac, char **av);
int	check_m(char *str, int s);
char	**ft_atoa(char **str);
int	ft_atoi(char *str);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(int ac, char **av);
void	ft_putendl_fd(char *s, int fd);
void	sort_stack(t_stack **a, t_stack **b, t_stack **inst);
void	put_stack(t_stack **a, char **av);
int put_inst(t_stack **inst);
void	free_str1(char **str);
int	s_issort(t_stack *a);
int	ft_strcmp(char *s1, char *s2);
int is_inst(char *line);
void	free_stack(t_stack **a, t_stack **b, t_stack **inst);
void	push(t_stack **dest, t_stack **src);
void	reverse_rotate(t_stack **stack);
void	rr_rotate(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	r_rotate(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void s_swap(t_stack **a, t_stack **b);
int	stack_node(t_stack *a);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_g(char const *s1, char const *s2);
size_t	ft_strlen_g(const char *s);
int	ft_strlen(char *str);
int b_empty(t_stack *b);

#endif