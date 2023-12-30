# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 19:18:10 by tlupu             #+#    #+#              #
#    Updated: 2023/12/28 18:23:09 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
SRC = get_next_line_utils.c get_next_line.c\

BONUS = get_next_line_utils_bonus.c get_next_line_bonus.c\

all: $(NAME) 


$(NAME): 
	$(CC) -Wall -Wextra -Werror -c  $(SRC)
	ar rc $(NAME) *.o
	rm -f *.o
	
bonus: 
	$(CC) -c -Wall -Wextra -Werror $(BONUS)
	ar rc $(NAME) *.o
	rm -f *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
