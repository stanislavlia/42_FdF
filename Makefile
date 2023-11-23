NAME = fdf
NAME_B = fdfb
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror 
#FLAGS = 	#turn off flags for DEV

YELLOW = \033[33;49;1m
CYAN = \033[33;36;1m
END = \033[0;0m

MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_ARG = -framework OpenGl -framework AppKit

SRC = $(shell find src -name '*.c')
INCLUDES = -I includes
# B_SRC = $(wildcard bonus/*.c)

OBJ = ${SRC:.c=.o}
B_OBJ = ${B_SRC:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ)  $(MLX)
			$(CC) $(OBJ) $(MLX) $(MLX_ARG) -o $(NAME)
			@echo "$(YELLOW)${NAME} ✔️"
			@echo "$(CYAN)Mandatory files compiled successfully ✔️$(END)"

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


$(MLX):
	@make -s -C $(MLX_DIR)


$(NAME_B): 	$(B_OBJ)  $(MLX)
			$(CC) $(FLAGS) $(B_OBJ) $(MLX) $(MLX_ARG) -o $(NAME_B)
			@echo "$(YELLOW)${NAME_B} ✔️$(END)"

clean:
	${RM} ${OBJ}
	${RM} ${B_OBJ}


fclean: clean
	@make clean -C mlx
	${RM} ${NAME}
	${RM} ${NAME_B}


mlx:
	make re -C mlx

re: clean mlx all

check_leaks:
			leaks --atExit -- ./$(NAME)
norm:
			norminette src
			norminette includes/fdf.h

.PHONY: all clean fclean re mlx check_leaks norm
