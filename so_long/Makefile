# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/05 14:12:29 by leon              #+#    #+#              #
#    Updated: 2023/08/23 12:51:31 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for printing
GREEN = \033[0;32m
NC = \033[0m # No Color

# NAME
NAME		= so_long

# SOURCES
SRCS		= main.c check_map.c sprites.c sprites_helper.c check_map_helper.c\
			debug.c has_valid_paths.c has_valid_paths_helper.c game.c init_game.c

# DIRECTORIES AND PATHS
INCLDIR		:= incl/
INCS		:= -I ./incl/ -I/usr/include -I/usr/include -Imlx
SRCDIR		:= src/
OBJDIR		:= obj/
LIBFTDIR	:= libft/
HEADER		:= incl/so_long.h

# LIBRARIES
LIBFT		:= $(LIBFTDIR)libft.a
LIBMLX		:= minilibx/libmlx.a

# COMPILER & COMMANDS
CC			:= cc
RM			:= rm -f

# HEADERS
HEADERS		:= $(addprefix $(INCLDIR)/, so_long.h libft.h get_next_line.h ft_printf.h)

# FLAGS
CFLAGS		:= -Wall -Wextra -Werror -O3 -g
LIBFLAG		:= -L$(LIBFTDIR)
LIBFTLIB	:= -lft
MLXFLAGS 	:= -L./minilibx -lmlx -lbsd -lXext -lX11 -lm

# OBJECTS
OBJ			:= $(SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJDIR), $(OBJ))

# COMPILATION RULES
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# RULES
all: $(NAME) $(LIBFT)

# Compile libft.a
$(LIBFT): $(LIBFTDIR)*.c
	@$(MAKE) -C $(LIBFTDIR) all --no-print-directory

$(NAME): $(HEADERS) $(LIBFT) $(LIBMLX) $(OBJDIR) $(OBJS) 
		@$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $(NAME) $(LIBFLAG) $(LIBFTLIB) $(MLXFLAGS)
		@echo "$(GREEN)$(NAME) is ready!$(NC)"

$(OBJDIR):
		mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
		$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Create links of headers in incl folder
$(HEADERS):
		ln $(LIBFTDIR)libft.h $(INCLDIR)libft.h
		ln $(LIBFTDIR)ft_printf.h $(INCLDIR)ft_printf.h
		ln $(LIBFTDIR)get_next_line.h $(INCLDIR)get_next_line.h

clean:
		$(RM) $(OBJS)
		$(RM) -r $(OBJDIR)
		$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFTDIR) fclean
		$(RM) $(INCLDIR)libft.h
		$(RM) $(INCLDIR)ft_printf.h
		$(RM) $(INCLDIR)get_next_line.h

re:		fclean all

.PHONY:	all clean fclean re
