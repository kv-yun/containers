# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yun <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 06:47:55 by yun               #+#    #+#              #
#    Updated: 2021/11/14 11:55:30 by yun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_containers

DIR	=	./Tests/

SRCS	=	main.cpp ./Tests/std_stack_test.cpp ./Tests/ft_stack_test.cpp
SRCS	+=	./Tests/std_vector_test.cpp ./Tests/ft_vector_test.cpp
SRCS	+=	./Tests/std_pair_test.cpp ./Tests/ft_pair_test.cpp
SRCS	+=	./Tests/std_map_test.cpp ./Tests/ft_map_test.cpp

INC	=	./Iterators/reverse_iterator.hpp ./Iterators/map_iterator.hpp ./Iterators/vector_iterator.hpp ./Iterators/iterator_traits.hpp
INC	+=	./Vector/vector.hpp ./Map/map.hpp ./Stack/stack.hpp ./Tests/tests.hpp ft_containers.hpp ./Vector/vector.ipp ./Map/map.ipp
INC	+=	./Vector/vector_iterator.ipp ./Map/map_iterator.ipp

OBJS	=	${SRCS:.cpp=.o}

HEADER	=	ft_containers.hpp

CC	=	clang++

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -I./Iterators/reverse_iterator.hpp -I./Iterators/map_iterator.hpp -I./Iterators/vector_iterator -I./ft_containers -I./Vector/vector.hpp -I./Stack/stack.hpp -I./Map/map.hpp -I./Tools/tests.hpp

all	:	${NAME}

%.o	:	%.cpp
		${CC} -c ${FLAGS} $< -o $@

${NAME}	:	${OBJS} ${INC}
		${CC} -o ${NAME} ${FLAGS} ${OBJS}

clean	:
		rm -fr ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re	:	fclean ${NAME}	
