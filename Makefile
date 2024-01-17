# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 10:28:37 by hakaraou          #+#    #+#              #
#    Updated: 2024/01/17 13:50:49 by hakaraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = mandatory/push_swap.c \
	mandatory/sort_utils/c_push.c mandatory/sort_utils/c_reverse_rotate.c mandatory/sort_utils/c_rotate.c mandatory/sort_utils/c_swap.c mandatory/sort_utils/move_top_a.c mandatory/sort_utils/move_top_b.c\
	mandatory/stack_utils/put_stack.c mandatory/stack_utils/s_issort.c mandatory/stack_utils/sort_stack.c mandatory/stack_utils/put_index.c mandatory/stack_utils/put_everything.c mandatory/stack_utils/put_cheap.c mandatory/stack_utils/put_target_b.c  mandatory/stack_utils/put_target_a.c\
	mandatory/string_utils/ft_atoi.c mandatory/string_utils/ft_check_utils.c mandatory/string_utils/ft_check.c mandatory/string_utils/ft_split.c mandatory/string_utils/ft_strjoin.c mandatory/string_utils/ft_substr.c \
	mandatory/utils/ft_free.c mandatory/utils/ft_len.c mandatory/utils/ft_putendl_fd.c \
	mandatory/sort_all/sort_to_b.c mandatory/sort_all/sort_to_a.c \

OBJ = $(SRC:.c=.o)

B_NAME = checker

B_SRC = bonus/get_inst/get_next_line_utils.c bonus/get_inst/get_next_line.c \
	bonus/sort_utils/c_push.c bonus/sort_utils/c_reverse_rotate.c bonus/sort_utils/c_rotate.c bonus/sort_utils/c_swap.c \
	bonus/stack_utils/put_inst.c bonus/stack_utils/put_stack.c bonus/stack_utils/s_issort.c bonus/stack_utils/sort_stack.c \
	bonus/string_utils/ft_atoi.c bonus/string_utils/ft_check_utils.c bonus/string_utils/ft_check.c bonus/string_utils/ft_split.c bonus/string_utils/ft_strjoin.c bonus/string_utils/ft_substr.c \
	bonus/utils/ft_free.c bonus/utils/ft_putendl_fd.c bonus/utils/ft_strcmp.c bonus/utils/ft_len.c bonus/utils/b_empty.c \
	bonus/checker_bonus.c \

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(B_NAME)

$(B_NAME) : $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(B_NAME)

%.o: %.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c -o $@ $<

bonus/%.o : %c bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJ) $(B_OBJ)

fclean : clean
	rm -f $(NAME) $(B_NAME)
	
re : fclean all

.PHONY : all clean fclean re