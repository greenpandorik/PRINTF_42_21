LIBFT = ./libft/libft.a

CC = gcc

NAME = libftprintf.a

SRCS =  ft_printf.c \
		ft_atoi_mod.c \
		ft_check_flags.c \
		ft_check_set.c \
		ft_display_management.c \
		ft_exception_flag.c \
		ft_flags_management_integer.c \
		ft_flags_management.c \
		ft_get_strlen.c \
		ft_itox.c \
		ft_ultox.c \
		ft_unsigned_itoa.c \
		ft_utils.c

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I libft.h

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all