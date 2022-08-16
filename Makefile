NAME1 = server
NAME2 = client
NAME3 = server_bonus
NAME4 = client_bonus
SRC1 = server.c
SRC2 = client.c
SRC3 = server_bonus.c
SRC4 = client_bonus.c
SRC_O1	= $(SRC1:.c=.o)
SRC_O2	= $(SRC2:.c=.o)
SRC_O3 = $(SRC3:.c=.o)
SRC_O4 = $(SRC4:.c=.o)
INCLUDES = ft_printf/libft/libft.h
CC	=	gcc
CFLAGS	=	-Werror -Wextra -Wall -g
MAKE = make
LIBFTA = libftprintf.a

all	:	$(NAME1) $(NAME2)
bonus : $(NAME3) $(NAME4)

$(NAME1)	: $(SRC_O1) $(LIBFTA)
	$(CC) $(CFLAGS) $(SRC_O1) libftprintf.a -o $(NAME1)
	
$(NAME2)   : $(SRC_O2) $(LIBFTA)
	$(CC) $(CFLAGS) $(SRC_O2) libftprintf.a -o $(NAME2)

$(NAME3)   : $(SRC_O3) $(LIBFTA)
	$(CC) $(CFLAGS) $(SRC_O3) libftprintf.a -o $(NAME3)
	
$(NAME4)   : $(SRC_O4) $(LIBFTA)
	$(CC) $(CFLAGS) $(SRC_O4) libftprintf.a -o $(NAME4)

libftprintf.a : 
	$(MAKE) -C ft_printf/
	cp  ft_printf/libftprintf.a .

%.o	:	%.c ft_printf/libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@


clean	:
	$(MAKE) -C ft_printf/libft/ clean
	$(MAKE) -C ft_printf/ clean
	rm -f $(SRC_O1) $(SRC_O2) $(SRC_O3) $(SRC_O4)

fclean	: clean
	$(MAKE) -C ft_printf/libft/ fclean
	$(MAKE) -C ft_printf/ fclean
	rm -f $(NAME1) $(NAME2)	$(NAME3) $(NAME4)
	rm -f libftprintf.a libft.a

re	: fclean all

.PHONY : clean fclean all re bonus
