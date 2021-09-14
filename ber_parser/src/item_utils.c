/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:42:18 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/14 16:42:40 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

void	destroy_item(t_read_list *item)
{
	if (item->str)
	{
		free(item->str);
		item->str = NULL;
	}
	free(item);
}

t_read_list	*get_first_item(t_read_list *item)
{
	t_read_list	*ptr;

	ptr = item;
	while (ptr->prev)
	{
		ptr = ptr->prev;
	}
	return (ptr);
}

void	destroy_list(t_read_list *item)
{
	t_read_list	*ptr;
	t_read_list	*temp;

	ptr = get_first_item(item);
	while (ptr)
	{
		temp = ptr->next;
		destroy_item(ptr);
		ptr = temp;
	}
}

char	*list_to_str(t_read_list *item)
{
	t_read_list	*ptr;
	char		*str;
	int			len;
	int			i;

	len = list_combined_str_len(item);
	ptr = get_first_item(item);
	str = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (ptr)
	{
		i += str_override(&str[i], ptr->str);
		ptr = ptr->next;
	}
	destroy_list(item);
	return (str);
}
