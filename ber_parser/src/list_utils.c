/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:17:23 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/14 16:42:35 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

t_read_list	*new_item(char *str, t_read_list *prev)
{
	t_read_list	*item;
	int			l;

	item = ft_calloc(1, sizeof(t_read_list));
	if (prev)
	{
		item->prev = prev;
		prev->next = item;
	}
	l = ft_strlen(str);
	item->str = ft_calloc(l + 1, sizeof(char));
	while (l-- > 0)
	{
		item->str[l] = str[l];
	}
	return (item);
}

int	list_combined_str_len(t_read_list *item)
{
	int			l;
	t_read_list	*ptr;

	l = 0;
	ptr = get_first_item(item);
	while (ptr)
	{
		l += ft_strlen(ptr->str);
		ptr = ptr->next;
	}
	return (l);
}

int	str_override(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

t_read_list	*make_str_array(char *map)
{
	int			s_i;
	int			f_i;
	t_read_list	*item;

	s_i = 0;
	f_i = 0;
	item = NULL;
	while (map[f_i])
	{
		if (map[f_i] == '\n')
		{
			map[f_i] = 0;
			item = new_item(&map[s_i], item);
			map[f_i] = '\n';
			s_i = f_i + 1;
		}
		f_i++;
	}
	if (map[s_i])
		item = new_item(&map[s_i], item);
	item = get_first_item(item);
	return (item);
}

int	list_size(t_read_list *item)
{
	t_read_list	*ptr;
	int			l;

	ptr = get_first_item(item);
	l = 0;
	while (ptr)
	{
		l++;
		ptr = ptr->next;
	}
	return (l);
}
