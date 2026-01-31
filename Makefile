# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 21:39:30 by ikawamuk          #+#    #+#              #
#    Updated: 2026/02/01 02:05:42 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Ccc

CC = cc
CFLAG = -Werror -Wall -Wextra -I$(INCDIR)
RMDIR = $(RM) -rf

SRCS =	$(addprefix $(SRCDIR)/, \
			main.c \
			clear_token.c \
			file_to_token_list.c \
			read_in_bulk.c \
			tokenize.c \
			compile.c \
			create_assemble_src.c \
			put_operations.c \
			assemble.c \
			error_at.c \
		) \

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

SRCDIR = src
OBJDIR = obj
INCDIR = include
ASMDIR = asm

all:$(NAME)

$(NAME):$(OBJS) | $(ASMDIR)
	$(CC) $(CFLAG) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAG) -c $< -o $@

$(ASMDIR):
	@mkdir -p $@

clean:
	@$(RMDIR) $(OBJDIER)
	@$(RMDIR) $(ASMDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
