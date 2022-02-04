# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claclau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 17:03:28 by claclau           #+#    #+#              #
#    Updated: 2022/02/04 17:31:15 by claclau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
       ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
       ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
       ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror
INC = libft.h

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar cr $(NAME) $(OBJS)

bonus: $(BONUS_OBJS) $(INC)
	$(CC) $(CFLAGS) -c $(BONUS)
	ar cr $(NAME) $(BONUS_OBJS)

clean:
	rm -rfv $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rfv $(NAME)

re: fclean all

norme:
	norminette $(SRC) $(BONUS)
