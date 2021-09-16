NAME		=	so_long
CC			=	clang
AR			=	ar -rcs
CFLAGS		=	-Wall -Werror -Wextra 

SRC_DIR			=	src
OBJS_DIR		=	objs

RAW			=	can_move_to.c \
				close_win.c \
				count_entities.c \
				c_to_i.c \
				game_tick.c \
				get_ent_by_pos.c \
				make_overlay.c \
				new_entity.c \
				pos_has_entity.c \
				pressed_key.c \
				translate_player.c \
				fill_entities.c \
				load_sprites.c \
				get_player.c \
				get_exit.c \
				load_enemy.c \
				load_exit.c \
				load_meat.c \
				load_player.c \
				load_snow.c \
				load_tree.c \
				img_from_entity.c \
				make_base_map.c \
				get_image_by_type.c \
				start_game.c \
				main.c \
				destroy_entity.c \
				destroy_entities.c \
				destroy_sprite.c \
				destroy_game_sprites.c

INCLUDES		=	-I. -I./img_utils -I./ber_parser -I./libft -I./mlx_linux
LIBS			=	-L./img_utils -limg_utils -L./ber_parser -lberparser -L./mlx_linux -lmlx_Linux -L./libft -lft -lXext -lX11 -lm

OBJS		=	$(addprefix $(OBJS_DIR)/,${RAW:.c=.o})
SRC			=	$(addprefix $(SRC_DIR)/,$(RAW))

.PHONY:	clean fclean re norms

all:	$(NAME)

$(NAME): $(OBJS) ft utils parser mlx
	$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRC_DIR)/%.c
	@echo "Compiling $< into $@"
	@mkdir -p $(OBJS_DIR)
	$(CC) -c $(CFLAGS) $< $(INCLUDES) -o $@

bonus: $(NAME)

clean:
	rm -rfd $(OBJS_DIR)
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./img_utils clean
	@$(MAKE) -C ./ber_parser clean

fclean:	clean
	rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean
	@$(MAKE) -C ./img_utils fclean
	@$(MAKE) -C ./ber_parser fclean

re:	fclean all

ft:
	@$(MAKE) -C ./libft

norms:
	norminette ./src
	norminette ./libft
	norminette ./ber_parser
	norminette ./img_utils

utils:
	@$(MAKE) -C ./img_utils

mlx:
	@$(MAKE) -C ./mlx_linux

parser:
	@$(MAKE) -C ./ber_parser