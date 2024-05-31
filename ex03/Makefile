# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 19:00:40 by agan              #+#    #+#              #
#    Updated: 2024/05/23 19:00:41 by agan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# program name
NAME	= Intern

# compiler
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow -g
RM		= rm -fr

# directories
INC_DIR = ./includes
INC 	= -I $(INC_DIR)
SRC_DIR = ./sources

# build files
SRCS	= $(addprefix $(SRC_DIR)/, \
	Bureaucrat.cpp \
	main.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	Intern.cpp)
OBJS 	= ${SRCS:.cpp=.o}

#------------------------------------------------------------------------

# colours
GREEN = \033[0;32m
B_GREEN = \033[1;32m
BROWN = \033[0;33m
B_BROWN = \033[1;33m
END = \033[0m

#------------------------------------------------------------------------

all: $(NAME)

# build program
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(B_GREEN)$(NAME) compiled$(END)"

# build objects
.cpp.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o} $(INC)
	@echo "$(B_GREEN)$< compiled.$(END)"

# clean rules
clean:
	@rm -fr $(OBJS)

fclean: clean
	@rm -fr $(NAME)
	@echo "$(B_GREEN)fclean completed$(END)"

re: fclean all

.PHONY: all clean fclean re
