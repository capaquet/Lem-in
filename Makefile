# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achirat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 10:47:27 by achirat           #+#    #+#              #
#    Updated: 2018/05/07 17:59:49 by achirat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main2.c \
	  get_info.c \
	  check_son.c \
	  ft_analyse_flag.c \
	  super_scoot.c \
	  super_scoot2.c \
	  ant_init.c \
	  combinatoire.c \
	  combinatoire2.c \
	  distribute.c \
	  tools.c \
	  tools2.c \
	  ft_check_coord.c \
	  ft_check2.c \
	  check_strend.c \
	  check_line.c \
	  check_is_digit.c

SRC_MEGA = $(SRC_TREE) $(SRC)

VPATH = ./src\

OBJ = $(addprefix obj/, $(SRC_MEGA:.c=.o))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -Ilibft/includes -Isrc/

LDLIBS = -lft

LDFLAGS = -Llibft/ $(LDLIBS)

.PHONY: clean re all fclean

all:$(NAME)

$(NAME): $(OBJ)
	@echo "Wait until done, please"
	@make -C libft
	@echo "Libft compile"
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "$(NAME) compile"

obj/%.o: %.c
	@mkdir obj 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $^ $(CPPFLAGS)

clean:
	@rm -rf $(OBJ)
	@rmdir obj 2> /dev/null || true
	@make -C libft/ clean
	@echo "Clean done"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "Fclean done"

re: fclean all
