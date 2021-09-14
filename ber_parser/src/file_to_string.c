/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:12:06 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/14 16:50:30 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	get_fd(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nArquivo nao encontrado.\n", 1);
		exit(EXIT_FAILURE);
		return (-1);
	}
	return (fd);
}

char	*file_to_string(const char *path)
{
	int			fd;
	int			read_c;
	char		*buf;
	t_read_list	*list;

	fd = get_fd((char *)path);
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
	close(fd);
	if (list)
		return (list_to_str(list));
	ft_putstr_fd("Error\nArquivo em branco.\n", 1);
	exit(EXIT_FAILURE);
	return (NULL);
}
