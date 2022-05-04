NAME = libftprintf.a

SRCS = ft_printf.c \
       sources/ft_decuint_len_base.c \
       sources/ft_int_len.c \
       sources/ft_putnbr_base_fd.c \
       sources/ft_putunbr_fd.c \
       sources/ft_treat_c.c \
       sources/ft_treat_s.c \
       sources/ft_treat_p.c \
       sources/ft_treat_d.c \
       sources/ft_treat_u.c \
       sources/ft_treat_x.c \
       sources/ft_treat_X.c \

OBJS = $(SRCS:.c=.o)

CC = gcc -nostartfiles

CFLAGS = -c -Wall -Wextra -Werror

INC = ft_printf.h

all  : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INC) $(SRCS) -I./libft -L libft/ -l ft
	ar crs $(NAME) $(OBJS)

clean :
	rm -rfv $(OBJS)
	$(MAKE) clean -C ./libft

fclean : clean
	rm -rfv $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all
