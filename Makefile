HEADER_INC	=	-I./include

SRC_PATH	=	./src/

SRCS		=	main.c \
				utils.c \
				init.c \
				actions.c \
				routine.c \
				exit.c \

OBJ_PATH	=	./bin/

OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

CC			=	gcc

CFLAGS		=	-Wall

CFLAGS_FSAN	=	-Wall -Werror -Wextra -g3 -fsanitize=address

NAME		=	philo

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CFLAGS) $(HEADER_INC) -c $< -o $@

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				rm -rf $(OBJ_PATH)

fclean:			clean
				rm -f $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re bonus
