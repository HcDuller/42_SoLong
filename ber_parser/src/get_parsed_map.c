/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parsed_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:46:10 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/16 17:14:36 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

t_lines	get_parsed_map(char *path)
{
	t_lines		map_lines;
	t_read_list	*item;
	char		*map;

	item = NULL;
	check_ber_ext(path);
	map = file_to_string(path);
	replace_chars(&map);
	map_is_big_enough(map);
	has_forbidden_char(map);
	has_just_one_player(map);
	has_one_or_more_of(map, '2');
	has_one_or_more_of(map, '4');
	item = make_str_array(map);
	free(map);
	map_lines = break_into_lines(item);
	has_distinct_line_sizes(&map_lines);
	map_boundaries_ok(&map_lines);
	return (map_lines);
}
