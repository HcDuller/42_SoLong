NAME		=	libberparser.a

CC			:=	clang
AR			:=	ar -rcs
CFLAGS		:=	-Wall -Wextra -Werror

SRC_DIR		:=	src
OBJS_DIR	:=	obj

INCLUDES	:=	-I../libft -I.
LIBS		:=	-L../libft -lft

SRC_FILES	:=	file_to_string.c \
				replace_chars.c \
				count_lines.c \
				has_forbidden_char.c \
				line_size.c \
				break_into_lines.c \
				map_boundaries_ok.c \
				has_just_one_player.c \
				has_one_or_more_of.c \
				free_lines.c \
				has_distinct_line_sizes.c \
				get_parsed_map.c \
				destroy_map.c \
				check_ber_ext.c \
				list_utils.c \
				item_utils.c

OBJS		=	$(addprefix $(OBJS_DIR)/,$(SRC_FILES:.c=.o))

.PHONY:		clean fclean

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) -g $(CFLAGS) $< $(INCLUDES) -c -o $@

clean:
	rm -rfd $(OBJS_DIR) 

re: clean all
