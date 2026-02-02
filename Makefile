# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 21:39:30 by ikawamuk          #+#    #+#              #
#    Updated: 2026/02/02 13:00:18 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ccc

CC = cc 
CFLAG = -Werror -Wall -Wextra -I$(INCDIR)
RMDIR = $(RM) -rf

SRCS =	$(addprefix $(SRCDIR)/, \
			main.c \
			arena.c \
			clear_token.c \
			file_to_ast.c \
			file_to_token_list.c \
			token_list_to_ast.c \
			read_in_bulk.c \
			tokenize.c \
			node.c \
			clear_ast.c \
			expr.c \
			compile.c \
			create_assemble_src.c \
			calc_ast.c \
			put_operations.c \
			assemble.c \
			error_at.c \
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
