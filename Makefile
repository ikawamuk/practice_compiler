# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 21:39:30 by ikawamuk          #+#    #+#              #
#    Updated: 2026/01/31 21:39:31 by ikawamuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= Ccc

CC = cc
CFLAG= -Werror -Wall -Wextra -I$(INCDIR)
RMDIR = $(RM) -rf

SRCS =	$(addprefix $(SRCDIR)/, \
			main.c \
			read_in_bulk.c \
			compile.c \
			create_assemble_src.c \
			assemble.c \
		) \

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

SRCDIR = src
OBJDIR = obj
INCDIR = inlude

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	@$(RMDIR) $(OBJDIER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
