# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olarseni <olarseni@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 20:39:53 by olarseni          #+#    #+#              #
#    Updated: 2025/01/22 23:57:04 by olarseni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 DEFINITIONS                                  #
################################################################################

# Program name
NAME	=	so_long

# Sources with VPATH
VPATH	=	srcs srcs/game_interface srcs/error_checker

SRCS	=	main.c					\
			read_map.c				\
			init_game_interface.c	\
			init_map.c				\
			init_pj.c				\
			init_npcs.c				\
			game_interface_utils.c	\
			init_collectable.c		\
			init_sprites.c			\
			init_exit.c				\
			init_counter.c			\
			destroy_game_interface.c\
			destroy_sprites.c		\
			destroy_map.c			\
			destroy_collectable.c	\
			destroy_npcs.c			\
			exit_error.c			\
			has_map_checks.c		\
			has_valid_path.c		\
			is_map_checks.c			\
			is_valid_map.c			\
			collisions.c			\
			movement.c				\
			render.c				\
			exit_game.c				\
			print_counter.c

# Objects
ODIR	=	objects
OBJS	=	$(SRCS:%.c=$(ODIR)/%.o)

# Includes
IDIR	=	includes

# LIBFT
PRINTF	=	ft_printf/includes
LDIR	=	libft
MINIDIR	=	minilibx-linux
MINILIB =	libmlx.a
LIBFT	=	libft.a

# Compiler
CC		=	cc

# Flags
CFLAGS	=	-Wall -Wextra -Werror -g
IFLAGS	=	-I$(IDIR) -I$(LDIR) -I$(MINIDIR) -I$(LDIR)/$(PRINTF)
LFLAGS	=	-L$(LDIR) -lft -L$(MINIDIR) -lmlx -lXext -lX11 -lbsd 

# Bonus flag
bonus: CFLAGS += -DVALID_CHARS='"01CPEN"'
bonus: CFLAGS += -DBONUS=1

################################################################################
#                                  COLORS                                      #
################################################################################

RESET	=	\033[0m
LGREEN	=	\033[38;5;150m
CYAN	=	\033[38;5;195m
DRED	=	\033[38;5;124m
RED		=	\033[38;5;160m
SAND	=	\033[38;5;222m
LPURPLE	=	\033[38;5;104m

################################################################################
#                                 FONT STYLES                                  #
################################################################################

BOLD	=	\033[1m
FAINT	=	\033[2m
ITALIC	=	\033[3m
UNDERL	=	\033[4m
BLINK	=	\033[5m

################################################################################
#                                   RULES                                      #
################################################################################

all: $(NAME)

$(ODIR)/%.o: %.c | $(ODIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@make --silent header
	@make --silent compile
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)
	@echo "$(LGREEN)$(BOLD)COMPILATION FINISHED $(RESET)🎉"
	@make --silent footer

bonus: $(NAME)

$(BNAME): $(OBJS)
	@make --silent header
	@make --silent compile
	@$(CC) -DVALID_CHARS='"01CPEN"' $(CFLAGS) $(IFLAGS) -o $@ $^ $(LFLAGS)
	@echo "$(LGREEN)$(BOLD)COMPILATION FINISHED $(RESET)🎉"
	@make --silent footer

$(ODIR):
	@mkdir -p $@

clean:
	@rm -rf $(ODIR)
	@$(MAKE) --silent -C $(MINIDIR) clean 1>/dev/null
	@$(MAKE) --silent -C $(LDIR) clean 1>/dev/null

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --silent -C $(LDIR) fclean 1>/dev/null

re: fclean all

header:
	@echo "$$so_long_art"
	@sleep 0.2
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"
	@echo "\t\t\t$(SAND)$(FAINT)$(ITALIC)WELCOME TO $(DRED)$(BOLD)$(NAME)$(RESET) $(SAND)$(FAINT)$(ITALIC)PROGRAM$(RESET)"
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"
	
footer:
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"
	@echo "$(LPURPLE)$(BOLD)Compiled by:$(RESET) $(CYAN)$$USER$(RESET)"
	@echo "$(LPURPLE)$(BOLD)Compiled date:$(RESET) $(CYAN)$(shell date '+%d/%m/%Y %H:%M:%S')$(RESET)"
	@echo "$(FAINT)$(CYAN)$(line)$(RESET)"

compile: $(OBJS)
	@echo "$(LGREEN)$(BOLD)$(FAINT)START COMPILATION: $(RESET)"
	@sleep 0.1
	@echo "$(LGREEN)$(FAINT)OBJS...$(RESET)"
	@sleep 0.1
	@echo "$(LGREEN)$(FAINT)LIBFT...$(RESET)"
	@make --silent -C $(LDIR) $(LIBFT)
	@echo "$(LGREEN)$(FAINT)MINILIB...$(RESET)"
	@make --silent -C $(MINIDIR) 2>/dev/null 1>/dev/null
	@sleep 0.1
	@echo "$(LGREEN)$(FAINT)$(NAME)...$(RESET)"
	@sleep 0.1

.PHONY: all clean fclean re header

################################################################################
#                                 VARIABLES                                    #
################################################################################

# A simple line made with '='
define line
================================================================================
endef

export line


define so_long_art
\033[38;5;247m
              .... NO! ...                  ... MNO! ...
             ..... MNO!! ...................... MNNOO! ...
           ..... MMNO! ......................... MNNOO!! .
          .... MNOONNOO!   MMMMMMMMMMPPPOII!   MNNO!!!! .
           ... !O! NNO! MMMMMMMMMMMMMPPPOOOII!! NO! ....
              ...... ! MMMMMMMMMMMMMPPPPOOOOIII! ! ...
             ........ MMMMMMMMMMMMPPPPPOOOOOOII!! .....
             ........ MMMMMOOOOOOPPPPPPPPOOOOMII! ...  
              ....... MMMMM..    OPPMMP    .,OMI! ....
               ...... MMMM::   o.,OPMP,.o   ::I!! ...                
                   .... NNM:::.,,OOPM!P,.::::!! ....                 
                    .. MMNNNNNOOOOPMO!!IIPPO!!O! .....               
                   ... MMMMMNNNNOO:!!:!!IPPPPOO! ....                
                     .. MMMMMNNOOMMNNIIIPPPOO!! ......               
                    ...... MMMONNMMNNNIIIOO!..........
                 ....... MN MOMMMNNNIIIIIO! OO ..........
              ......... MNO! IiiiiiiiiiiiI OOOO ...........
            ...... NNN.MNO! . O!!!!!!!!!O . OONO NO! ........
             .... MNNNNNO! ...OOOOOOOOOOO .  MMNNON!........
             ...... MNNNNO! .. PPPPPPPPP .. MMNON!........
                ...... OO! ................. ON! .......
                   ................................

$(RED) @@@@@@    @@@@@@                  @@@        @@@@@@   @@@  @@@   @@@@@@@@ 
@@@@@@@   @@@@@@@@                 @@@       @@@@@@@@  @@@@ @@@  @@@@@@@@@ 
$(RED)$(FAINT)!@@       @@!  @@@                 @@!       @@!  @@@  @@!@!@@@  !@@       
!@!       !@!  @!@                 !@!       !@!  @!@  !@!!@!@!  !@!       
!!@@!!    @!@  !@!                 @!!       @!@  !@!  @!@ !!@!  !@! @!@!@ 
$(DRED) !!@!!!   !@!  !!!                 !!!       !@!  !!!  !@!  !!!  !!! !!@!! 
     !:!  !!:  !!!                 !!:       !!:  !!!  !!:  !!!  :!!   !!: 
    !:!   :!:  !:!                  :!:      :!:  !:!  :!:  !:!  :!:   !:: 
$(DRED)$(FAINT):::: ::   ::::: ::  :::::::::::::   :: ::::  ::::: ::   ::   ::   ::: :::: 
:: : :     : :  :   :::::::::::::  : :: : :   : :  :   ::    :    :: :: :  $(RESET)

endef

export so_long_art
