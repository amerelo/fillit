# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matirell <matirell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/19 21:47:32 by matirell          #+#    #+#              #
#    Updated: 2015/12/20 15:32:33 by matirell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = fillit.a
NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC =	ft_add_on_list.c	ft_cut_tetri_plus.c	ft_puttab.c \
	ft_check_block.c	ft_memalloc.c		ft_solve_tetri.c \
	ft_check_block_plus.c	ft_memset.c	ft_solve_tetri_plus.c \
	ft_check_tetri.c	ft_place.c	ft_test_2.c \
	ft_putendl.c		ft_power_x.c         ft_test_isvalid.c\
	ft_create_table.c	ft_putchar.c	ft_unplace.c \
	ft_cut_tetri.c		ft_create_list_element.c

SRC1 = $(SRC:.c=.o)

all: $(NAME)
$(NAME) :
	@echo "Processing files..."
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(LIBNAME) $(SRC1)
	@ranlib $(LIBNAME)
	@echo "Library $(LIBNAME) created "
	@gcc $(FLAG) -o $(NAME) main.c $(LIBNAME)
	@echo "$(NAME) created !"
	@rm -rf $(LIBNAME)
	@echo "Library $(LIBNAME) removed !"
clean:
	@rm -rf $(SRC1)
	@echo "Removing object files"
fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) removed !"
re: fclean all
