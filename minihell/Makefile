# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 01:38:53 by smargine          #+#    #+#              #
#    Updated: 2023/12/11 18:21:38 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for printing
GREEN = \033[0;32m
RESET = \033[0m

# NAME
NAME		= minishell

# SOURCES
SRCS := main.c\
		lexer/ft_lexer.c\
		lexer/ft_lexer_split_count.c lexer/ft_lexer_split_fill.c lexer/ft_lexer_split_fill_help.c\
		lexer/tokenizer.c\
		lexer/expander.c\
		lexer/expander_env.c\
		lexer/ft_helper_cmd.c\
		lexer/ft_helper_path_and_op.c\
		executor/executor_1.c executor/executor_helper_0.c executor/executor_helper_1.c executor/executor_helper_2.c\
		executor/ft_redirections.c\
		executor/ft_parser.c executor/parser_help.c\
		executor/builtins/cd.c executor/builtins/echo.c executor/builtins/env.c  executor/builtins/exit.c\
		executor/builtins/export.c executor/builtins/pwd.c executor/builtins/unset.c\
		signals/ft_signals.c\
		utils/clean.c utils/error.c utils/helper_1.c utils/helper_2.c\

# DIRECTORIES AND PATHS
INCLDIR		:= incl/
INCS		:= -I ./incl/ -I/usr/include
SRCDIR		:= src/
OBJDIR		:= obj/
LEXDIR		:= lexer/
EXECDIR		:= executor/
BINDIR		:= builtins/
UTILDIR		:= utils/
SIGDIR		:= signals/
LIBFTDIR	:= libft/
HEADER		:= incl/minishell.h

# LIBRARIES
LIBFT		:= $(LIBFTDIR)libft.a

# COMPILER & COMMANDS
CC			:= cc
RM			:= rm -f

# HEADERS
HEADERS		:= $(addprefix $(INCLDIR)/, minishell.h libft.h get_next_line.h ft_printf.h)

# FLAGS
CFLAGS		:= -Wall -Wextra -Werror
LIBFLAG		:= -L$(LIBFTDIR)
LIBFTLIB	:= -lft
RLFLAG		:= -lreadline

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

$(NAME): $(HEADERS) $(LIBFT) $(OBJDIR) $(OBJS) 
		@$(CC) $(CFLAGS) $(OBJS) $(INCS) -o $(NAME) $(LIBFLAG) $(LIBFTLIB) $(RLFLAG)
		@echo "$(GREEN)./$(NAME) is ready!$(RESET)"

$(OBJDIR):
		mkdir $(OBJDIR)
		mkdir $(OBJDIR)$(LEXDIR)
		mkdir $(OBJDIR)$(EXECDIR)
		mkdir $(OBJDIR)$(EXECDIR)$(BINDIR)
		mkdir $(OBJDIR)$(UTILDIR)
		mkdir $(OBJDIR)$(SIGDIR)

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
