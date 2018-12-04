# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:49:41 by anabaoui          #+#    #+#              #
#    Updated: 2018/11/23 15:09:53 by anabaoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror -c *.c
	@ar rc $(NAME) *.o

clean :
	@rm -f *.o

fclean : clean
	@rm -f $(NAME)

re : fclean all
