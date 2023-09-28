# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 13:56:36 by lgrimmei          #+#    #+#              #
#    Updated: 2023/09/26 17:57:49 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for printing
GREEN = \033[0;32m
NC = \033[0m # No Color

# NAME
NAME		= philo

# SOURCES
SRCS		= main.c utils_and_activities.c time_and_log.c parse_data.c routine.c setters.c getters.c clean.c

# DIRECTORIES AND PATHS
INCLDIR		:= incl/
INCS		:= -I ./incl/ -I/usr/include -I/usr/include
SRCDIR		:= src/
OBJDIR		:= obj/
HEADER		:= incl/philosophers.h

# COMPILER & COMMANDS
CC			:= cc
RM			:= rm -f

# FLAGS
CFLAGS		:= -Wall -Wextra -Werror

# OBJECTS
OBJ			:= $(SRCS:.c=.o)
OBJS		:= $(addprefix $(OBJDIR), $(OBJ))

# COMPILATION RULES
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# RULES
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) 
		@$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $(NAME)
		@echo "$(GREEN)$(NAME) is ready!$(NC)"

$(OBJDIR):
		mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
		$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		$(RM) -r $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re