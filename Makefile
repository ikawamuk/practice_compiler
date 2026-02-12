# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 21:39:30 by ikawamuk          #+#    #+#              #
#    Updated: 2026/02/12 15:35:54 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ccc

CC = cc 
CFLAG = -Werror -Wall -Wextra -I$(INCDIR) -g -O0
RMDIR = $(RM) -rf

SRCS =	$(addprefix $(SRCDIR)/, \
			main.c \
			$(addprefix util/, \
				arena.c \
				error_at.c \
			) \
			$(addprefix slurp_file/, \
				slurp_file.c \
				file_path_to_str.c \
			) \
			$(addprefix tokenize/, \
				tokenize.c \
				create_token_list.c \
				has_filled_token.c \
				consumes_operator.c \
				is_identifier_char.c \
			) \
			$(addprefix parse/, \
				add.c \
				assign.c \
				equality.c \
				expr.c \
				ident.c \
				is_expect_op.c \
				mul.c \
				new_binary.c \
				new_ident_leaf.c \
				new_num_leaf.c \
				num.c \
				parse.c \
				pri.c \
				program.c \
				relational.c \
				stmt.c \
				unary.c \
				local_variable.c \
				value.c \
			) \
			$(addprefix compile/, \
				compile.c \
				create_asm_file.c \
				generate_src.c \
				write_assemble_src.c \
				generate.c \
				gen_op_table.c \
				$(addprefix src_generator_op/, \
					generate_add.c \
					generate_equal.c \
					generate_less_than.c \
					generate_not_equal.c \
					generate_div.c \
					generate_less_equal.c \
					generate_mul.c \
					generate_sub.c \
				) \
				assemble.c \
			) \
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
