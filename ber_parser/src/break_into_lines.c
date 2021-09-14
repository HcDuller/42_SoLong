/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_into_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:18:39 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/09 21:24:55 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

t_read_list	*free_and_get_next(t_read_list *item)
{
	t_read_list	*ptr;

	ptr = item->next;
	free(item);
	item = NULL;
	return (ptr);
}

t_lines	break_into_lines(t_read_list *item)
{
	t_read_list	*ptr;
	int			l;
	int			i;
	t_lines		map;

	ptr = get_first_item(item);
	l = list_size(item);
	map.size = l;
	map.lines = ft_calloc(l + 1, sizeof(char **));
	i = 0;
	while (ptr)
	{
		map.lines[i] = ptr->str;
		ptr = free_and_get_next(ptr);
		i++;
	}
	return (map);
}
/*
t_lines	break_into_lines(char *str)
{
	int		index;
	int		inline_index;
	t_lines	res;

	res.size = count_lines(str);
	res.lines = ft_calloc(res.size + 1, sizeof(char *));
	index = 0;
	while (index < res.size && *str)
	{
		inline_index = 0;
		while (str[inline_index] != '\n' && str[inline_index])
		{
			inline_index++;
		}
		res.lines[index] = ft_substr(str, 0, inline_index);
		if (str[inline_index] == '\n')
			inline_index++;
		str += inline_index;
		index++;
	}
	res.lines[index] = NULL;
	return (res);
}
*/