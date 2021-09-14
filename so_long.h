#ifndef SO_LONG_H
# define SO_LONG_H
# include <libft.h>
# include <berparser.h>
# include <mlx.h>
# include <fcntl.h>
# include <img_utils.h>

typedef struct s_entity
{
	int		x;
	int		y;
	int		active;
	int		spr_i;
	char	type;
}	t_entity;

typedef struct s_sprites
{
	t_mlx_img	**sprite;
	int			n_sprites;
	char		type;
}	t_sprite;

typedef struct s_game_handler
{
	t_mlx_handler	mlx;
	t_mlx_img		*base_image;
	t_sprite		**sprites;
	t_entity		**entities;
	t_entity		*player;
	t_entity		*exit;
	int				fix_exit;
	int				tick;
	int				a_size;
	int				x_max;
	int				y_max;
	int				moves;
	int				handling_event;
	int				won;
}	t_game_handler;

int			close_win(t_game_handler *game);
int			pressed_key(int key_code, t_game_handler *game);
int			c_to_i(char c);
int			count_entities(char **lines, char c);
int			game_tick(t_game_handler *game);
int			pos_has_entity(t_entity **entities, int x, int y);
int			can_move_to(t_game_handler *game, int x, int y);
void		make_base_map(t_game_handler *game);
void		make_overlay(t_game_handler *game);
void		translate_player(t_game_handler *game, int d_x, int d_y);
void		start_game(t_game_handler *game, t_lines *map);
void		get_player(t_game_handler *game);
void		get_exit_from_entities(t_game_handler *game);
void		destroy_entity(t_entity *ent);
void		destroy_entities(t_entity **ent_ar);
void		destroy_sprite(t_mlx_handler *mlx, t_sprite *spr);
void		destroy_game_sprites(t_mlx_handler *mlx, t_sprite **spr);
t_mlx_img	*img_from_entity(t_game_handler *game, t_entity *ent);
t_mlx_img	*get_image_by_type(t_game_handler *game, char type);
t_entity	*get_ent_by_pos(t_entity **entities, int x, int y);
t_entity	**fill_entities(t_lines map);
t_entity	*new_entity(int x, int y, char type);
t_sprite	*load_snow(t_mlx_handler *mlx);
t_sprite	*load_tree(t_mlx_handler *mlx);
t_sprite	*load_meat(t_mlx_handler *mlx);
t_sprite	*load_player(t_mlx_handler *mlx);
t_sprite	*load_exit(t_mlx_handler *mlx);
t_sprite	*load_enemy(t_mlx_handler *mlx);
t_sprite	**load_sprites(t_mlx_handler *mlx);
#endif