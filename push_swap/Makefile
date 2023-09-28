# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 11:19:00 by lgrimmei          #+#    #+#              #
#    Updated: 2023/08/03 14:29:04 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

# SOURCES
SRCS        = push_swap.c stack_creation.c stack_creation_helper.c stack_operations.c\
			stack_calculations.c debug.c error_handling.c node_operations.c operations.c\
			perform_operation.c sort_less_than_5.c sort_more_than_5.c\
			moves_array.c calculate_moves.c

# DIRECTORIES AND PATHS
LIBFTDIR	:= libft/
PRINTFDIR	:= libft/ft_printf/
INCLDIR		:= incl/
SRCDIR		:= src/
OBJDIR		:= obj/
HEADER      := incl/push_swap.h
INCS		:= -I ./incl/

# LIBRARIES
LIBFT		:= $(LIBFTDIR)libft.a

# COMPILER & COMMANDS
CC          := cc
RM          := rm -f

# HEADERS
HEADERS		:= $(addprefix $(INCLDIR)/, push_swap.h libft.h)

# FLAGS
CFLAGS		:= -Wall -Wextra -Werror -O3 -g
LIBFLAG		:= -L$(LIBFTDIR)
LIBFTLIB	:= -lft

# OBJECTS
OBJ			:= $(SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(HEADERS) $(LIBFT) $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $(NAME) $(LIBFLAG) $(LIBFTLIB)

# Create links of headers in incl folder
$(HEADERS):
		ln $(LIBFTDIR)libft.h $(INCLDIR)libft.h
		ln $(PRINTFDIR)ft_printf.h $(INCLDIR)ft_printf.h

# Compile libft.a
$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

$(OBJDIR):
		mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(INCLDIR)libft.h
	$(RM) $(INCLDIR)ft_printf.h


re: fclean all

.PHONY: all clean fclean re