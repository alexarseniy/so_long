# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 22:54:11 by olarseni          #+#    #+#              #
#    Updated: 2024/10/19 17:08:44 by olarseni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#									DEFINITIONS								   #
################################################################################

NAME	=	libftprintf.a

SDIR	=	srcs
SRCS	=	ft_printf.c		\
			ft_write_char.c	\
			ft_write_str.c	\
			ft_write_ptr.c	\
			ft_write_int.c	\
			ft_write_uint.c	\
			ft_write_hex.c

ODIR	=	objects
OBJS	=	$(patsubst %.c, $(ODIR)/%.o, $(SRCS))

INCL	=	ft_printf.h
IDIR	=	includes

CC		=	cc
CFLAGS	=	-c -Wall -Werror -Wextra -I$(IDIR)

################################################################################
#									COLORS									   #
################################################################################

RESET		=	\033[0m
GREEN		=	\033[32m
BLUE		=	\033[34m
SAND		=	\033[38;5;180m
ROCK		=	\033[38;5;242m
YGREEN		=	\033[38;5;156m
BRED		=	\033[38;5;124m

################################################################################
#								  FONTS MODE								   #
################################################################################

BLINK		=	\033[5m
FAINT		=	\033[2m
BOLD		=	\033[1m

################################################################################
#									RULES									   #
################################################################################


# all rule
all: $(NAME)

# Compilation objects
$(ODIR)/%.o: $(SDIR)/%.c $(IDIR)/$(INCL) | $(ODIR)
	@$(CC) $(CFLAGS) -o $@ $<

# clean rule: Remove object files
clean:
	@rm -rf $(ODIR)
	@echo "$(BRED)$(BOLD)$(NAME) objects files are deleted!$(RESET)"

# full clean rule: Remove .a files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(BRED)$(BOLD)$(NAME) is deleted!$(RESET)"

# Recompile
re: fclean all

# name: name rule to compile libftprintft.a
$(NAME): $(OBJS) 
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)The library is compiled!$(RESET)"

$(ODIR):
	@mkdir -p $(ODIR)

tester:
	@make -C tester

# .PHONY: to except rules from files.
.PHONY: all clean fclean tester
