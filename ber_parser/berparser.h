/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   berparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:50:25 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/13 22:50:26 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BERPARSER_H
# define BERPARSER_H

# include <libft.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_lines {
	char	**lines;
	int		size;
	int		l_len;
}	t_lines;

typedef struct s_read_list {
	char				*str;
	struct s_read_list	*next;
	struct s_read_list	*prev;
}	t_read_list;

char		*file_to_string(const char *path);
void		replace_chars(char **str);
int			check_ber_ext(char *path);
int			count_lines(char *str);
int			has_forbidden_char(char *map);
int			has_just_one_player(char *map);
int			has_one_or_more_of(char *map, char obj);
int			has_distinct_line_sizes(t_lines *map_lines);
int			line_size(char *str);
t_lines		break_into_lines(t_read_list *item);
void		free_lines(t_lines map_lines);
void		map_boundaries_ok(t_lines *map);
t_lines		get_parsed_map(char *path);
void		destroy_map(t_lines *map);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
char		*pre_break(char *str);
char		*pos_break(char *str);
int			has_break(char *p);
int			get_next_line(int fd, char **line);
t_read_list	*new_item(char *str, t_read_list *prev);
void		destroy_item(t_read_list *item);
t_read_list	*get_first_item(t_read_list *item);
int			list_combined_str_len(t_read_list *item);
int			str_override(char *dest, char *src);
void		destroy_list(t_read_list *item);
char		*list_to_str(t_read_list *item);
t_read_list	*make_str_array(char *map);
int			list_size(t_read_list *item);
#endif