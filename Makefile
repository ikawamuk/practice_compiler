# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 21:39:30 by ikawamuk          #+#    #+#              #
#    Updated: 2026/03/04 02:46:55 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= cc0

CC = cc 
CFLAG = -Werror -Wall -Wextra -I$(INCDIR) -g -O0
RMDIR = $(RM) -rf

SRCS =	$(addprefix $(SRCDIR)/, \
			main.c \
			run_compiler.c \
			$(addprefix util/, \
				arena.c \
				error_at.c \
				xaalloc.c \
			) \
			$(addprefix read_src/, \
				read_src.c \
				file_path_to_str.c \
			) \
			$(addprefix tokenize/, \
				tokenize.c \
				has_filled_token.c \
				consumes_reserved.c \
				is_identifier_char.c \
			) \
			$(addprefix parse/, \
				$(addprefix new_node/, \
					new_binary.c \
					new_unary.c \
					new_ident_leaf.c \
					new_num_leaf.c \
					new_control_stmt.c \
					new_func_call_leaf.c \
					new_function.c \
				) \
				add.c \
				assign.c \
				equality.c \
				expr.c \
				variable.c \
				is_expected.c \
				ident.c \
				mul.c \
				num.c \
				parse.c \
				pri.c \
				program.c \
				relational.c \
				stmt.c \
				while_stmt.c \
				if_stmt.c \
				term.c \
				local_variable.c \
				value.c \
				condition.c \
				block.c \
				func_call.c \
				called_func_args.c \
				function.c \
				dup_token_str.c \
			) \
			$(addprefix compile/, \
				compile.c \
				create_assem_src.c \
				write_assemble_src.c \
				generate.c \
				gen_op_table.c \
				$(addprefix src_generator/, \
					generate_num.c \
					generate_operator.c \
					generate_add.c \
					generate_equal.c \
					generate_less_than.c \
					generate_not_equal.c \
					generate_div.c \
					generate_mod.c \
					generate_less_equal.c \
					generate_mul.c \
					generate_sub.c \
					generate_address.c \
					generate_local_variable.c \
					generate_expr_stmt.c \
					generate_return.c \
					generate_assign.c \
					generate_negative.c \
					generate_if.c \
					generate_while.c \
					generate_block.c \
					generate_func_call.c \
					generate_function.c \
					generate_dereference.c \
				) \
			) \
			assemble.c \
			link.c \
			replace_file_extention.c \
			$(addprefix debug/, \
				print_ast.c \
				print_token_list.c \
				print_program.c \
				print_var_list.c \
			) \
		) \

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

TEST = $(addprefix $(TESTDIR)/, test.sh)

SRCDIR = src
OBJDIR = obj
INCDIR = include
OUTDIR = out
TESTDIR = test

all:$(NAME)

$(NAME):$(OBJS) | $(OUTDIR)
	$(CC) $(CFLAG) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

$(OUTDIR):
	@mkdir -p $@

clean:
	@$(RMDIR) $(OBJDIR)
	@$(RMDIR) $(OUTDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	@./$(TEST)

debug:fclean
	$(MAKE) CFLAG="$(CFLAG) -g -O0"

.PHONY: all clean fclean re test
