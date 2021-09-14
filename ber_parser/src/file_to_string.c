
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:12:06 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/13 22:49:52 by hde-camp         ###   ########.fr       */
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

char	*file_to_string(const char *path)
{
	int			fd;
	int			read_c;
	char		*buf;
	t_read_list	*list;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nArquivo nao encontrado.\n", 1);
		exit(EXIT_FAILURE);
		return (NULL);
	}
	buf = ft_calloc(51, sizeof(char));
	read_c = read(fd, buf, 50);
	list = NULL;
	while (read_c > 0)
	{
		list = new_item(buf, list);
		ft_bzero(buf, 50);
		read_c = read(fd, buf, 50);
	}
	free(buf);
	if (list)
		buf = list_to_str(list);
	else
	{
		close(fd);
		ft_putstr_fd("Error\nArquivo em branco.\n", 1);
		exit(EXIT_FAILURE);
		return (NULL);
	}
	close(fd);
	return (buf);
}
