# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olarseni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 01:42:05 by olarseni          #+#    #+#              #
#    Updated: 2024/12/12 21:53:40 by olarseni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################
#	DEFINITIONS		#
#####################

NAME	=	libft.a

VPATH	=	ft_printf

SRCS	=	ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_strlen.c\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			get_next_line.c\
			get_next_line_utils.c


# Headers
HEADER		=	libft.h
GNL_HDR		=	get_next_line.h
PRINTF_HDR	=	ft_printf.h

#Headers dir
PRINTF_DIR	=	ft_printf/includes


OBJS	=	$(SRCS:.c=.o)

BSRCS	=	ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

BOBJS	=	$(BSRCS:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
IFLAGS	=	-I$(PRINTF_DIR)

#############
#	RULES	#
#############

%.o: %.c $(HEADER) $(GNL_HDR)
	$(CC) $(CFLAGS) -c -o $@  $< $(IFLAGS)

$(NAME): $(OBJS)
	$(MAKE) --silent -C ft_printf
	cp ft_printf/libftprintf.a ./libft.a
	ar -rc $@ $(OBJS)
	ranlib $@

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	ar -rc $(NAME) $(BOBJS)
	ranlib $(NAME)

clean:
	$(MAKE) --silent -C ft_printf clean
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	rm -f ft_printf/libftprintf.a
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
