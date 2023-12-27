# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 19:18:10 by tlupu             #+#    #+#              #
#    Updated: 2023/12/25 16:36:32 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
SRC = get_next_line_utils.c get_next_line.c\

all: $(NAME) 


$(NAME): 
	$(CC) -Wall -Wextra -Werror -c  $(SRC)
	ar rc $(NAME) *.o
	rm -f *.o
	
test: $(NAME)
	$(CC) $(CFLAGS) $(NAME) test.c
	make clean
	./a.out

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
