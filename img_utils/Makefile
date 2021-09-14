NAME		=	libimg_utils.a

CC			:=	clang
AR			:=	ar -rcs
CFLAGS		:=	-Wall -Wextra -Werror

SRC_DIR		:=	src
OBJS_DIR	:=	obj

INCLUDES	:=	-I. -I../libft -I../mlx_linux -I..
LIBS		:=	-L../libft -lft

SRC_FILES	:=	img_offset.c \
				overlay_images.c \
				img_from_file.c \
				override_images.c \
				new_blank_image.c \
				clear_image.c \
				img_from_file_2.c \
				destroy_t_mlx_img.c

OBJS		=	$(addprefix $(OBJS_DIR)/,$(SRC_FILES:.c=.o))

.PHONY:		clean fclean

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -g $(CFLAGS) $< $(INCLUDES) -c -o $@

clean:
	rm -rfd $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all