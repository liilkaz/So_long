NAME		=	so_long

BONUS_NAME	=	so_long_bonus

SRC			=	so_long.c map_check.c position.c lib_utils.c

BONUS_SRC	=	bonus_so_long.c bonus_position.c bonus_map_check.c \
				lib_utils.c ft_itoa.c bonus_help_func.c

HEADER		=	so_long.h

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit

RM			=	rm -f

GNL			=	Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c

OFF_COLOR		=	\033[0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
L_BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
L_BLUE			=	\033[0;36m

all		:	$(NAME)

$(NAME)	:	$(GNL) $(SRC) $(HEADER) 
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(GNL) $(SRC) -o $(NAME)
	@echo "$(GREEN)🌸Game compiled! 🌸 $(OFF_COLOR)"
	@echo "${GREEN}For $(YELLOW)START${GREEN} press command: $(YELLOW) ./so_long map.ber ${GREEN}! ${OFF_COLOR}"

bonus	:	$(GNL) $(BONUS_SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(GNL) $(BONUS_SRC) -o $(BONUS_NAME)
	@echo "${PURPLE}🐙Bonus compiled! 🐙${OFF_COLOR}"
	@echo "${GREEN}For $(YELLOW)START ${GREEN} press command: $(YELLOW) ./so_long_bonus map_bonus.ber ${GREEN}! ${OFF_COLOR}"

clean	:	
	@make clean -C mlx
	@echo "$(RED)Object files deleted!$(OFF_COLOR)"

fclean	:	clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "${RED}🗑 Program deleted!${OFF_COLOR}"

re		:	fclean all

.PHONY	:	all clean fclean bonus re