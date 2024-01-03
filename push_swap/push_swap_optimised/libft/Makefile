# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 11:32:38 by lgrimmei          #+#    #+#              #
#    Updated: 2023/07/06 15:14:17 by lgrimmei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_isalnum.c ft_isprint.c ft_bzero.c ft_isalpha.c ft_isascii.c\
					ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c\
					ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
					ft_strchr.c ft_strrchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
					ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
					ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
					*ft_memchr.c ft_strncmp.c ft_memcmp.c

BONUSSRCS		=	ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
					ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstlast.c ft_lstmap.c\

PRINTFSRCS		=	ft_printf/ft_printf.c ft_printf/ft_put_char.c ft_printf/ft_put_nbr_hex.c\
					ft_printf/ft_put_nbr.c ft_printf/ft_put_ptr.c ft_printf/ft_put_str.c\
					ft_printf/ft_put_unsigned.c 

OBJS			= $(SRCS:%.c=%.o)
BONUS_OBJS		= $(BONUSSRCS:%.c=%.o)
PRINTF_OBJS		= $(PRINTFSRCS:%.c=%.o)

CC				= cc
ARFLAGS 		= rcs
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
HEADER			= libft.h
PRINTFHEADER	= ft_printf/ft_printf.h

NAME			= libft.a

all:			$(NAME) bonus ft_printf

$(NAME):		$(OBJS) $(HEADER)
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus:			$(BONUS_OBJS) $(HEADER)
				$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

ft_printf:		$(PRINTF_OBJS) $(PRINTFHEADER)
				$(AR) $(ARFLAGS) $(NAME) $(PRINTF_OBJS)

clean:
				$(RM) $(OBJS) 
				$(RM) $(PRINTF_OBJS)
				$(RM) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re bonus ft_printf
