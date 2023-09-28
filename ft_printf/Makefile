# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 15:45:41 by lgrimmei          #+#    #+#              #
#    Updated: 2023/05/15 11:02:05 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c\
					ft_put_ptr.c\
					ft_put_char.c\
					ft_put_nbr_hex.c\
					ft_put_nbr.c\
					ft_put_str.c\
					ft_put_unsigned.c\

OBJS			= $(SRCS:%.c=%.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
HEADER			= ft_printf.h

NAME			= libftprintf.a

$(NAME):		$(OBJS) $(HEADER)
				ar rcs $(NAME) $(OBJS)
				
all:			$(NAME)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re bonus