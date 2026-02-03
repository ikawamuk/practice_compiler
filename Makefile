# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 21:39:30 by ikawamuk          #+#    #+#              #
#    Updated: 2026/02/03 18:53:58 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ccc

CC = cc 
CFLAG = -Werror -Wall -Wextra -I$(INCDIR)
RMDIR = $(RM) -rf

SRCS =	$(addprefix $(SRCDIR)/, \
			main.c \
			arena.c \
			read_in_bulk.c \
			tokenize.c \
			error_at.c \
			$(addprefix parse/, \
				add.c \
				expr.c \
				mul.c \
				new_num_leaf.c \
				parse.c \
				relational.c \
				equality.c \
				is_expect_op.c \
				new_binary.c \
				new_unary.c \
				pri.c \
				unary.c \
			) \
			compile.c \
			create_assemble_src.c \
			calc_ast.c \
			assemble.c \
		) \

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

TEST = $(addprefix $(TESTDIR)/, test.sh)

SRCDIR = src
OBJDIR = obj
INCDIR = include
ASMDIR = asm
TESTDIR = test

all:$(NAME)

$(NAME):$(OBJS) | $(ASMDIR)
	$(CC) $(CFLAG) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

$(ASMDIR):
	@mkdir -p $@

clean:
	@$(RMDIR) $(OBJDIR)
	@$(RMDIR) $(ASMDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	@./$(TEST)

debug:fclean
	$(MAKE) CFLAG="$(CFLAG) -g -O0"

.PHONY: all clean fclean re test
