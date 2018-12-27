# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:49:41 by anabaoui          #+#    #+#              #
#    Updated: 2018/12/18 19:12:00 by anabaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all : $(NAME)

$(NAME) :
	@make -C libft
	@gcc -Wall -Wextra -Werror src/*.c libft/libft.a -o $(NAME)

clean :
	@make clean -C libft

fclean :
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all
