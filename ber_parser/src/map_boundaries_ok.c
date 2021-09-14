/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundaries_ok.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:39:03 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 14:01:20 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

static	void	line_has_only_blocks(char *line, t_lines *map)
{
	while (*line)
	{
		if (*line != '1')
		{
			ft_putstr_fd("Error\nLinha inicial ou final tem brechas.\n", 1);
			destroy_map(map);
			exit(EINVAL);
		}
		line++;
	}
}

static	void	line_has_boundary_blocks(char *line, int l_size, t_lines *map)
{
	if (l_size == 0)
	{
		ft_putstr_fd("Error\nLinhas nao podem ser de tamanho zero.\n", 1);
		destroy_map(map);
		exit(EINVAL);
	}
	if (!(line[0] == line[l_size - 1] && line[0] == '1'))
	{
		ft_putstr_fd("Error\nHa alguma abertura lateral neste mapa.\n", 1);
		destroy_map(map);
		exit(EINVAL);
	}
}

static	void	check_map_size(t_lines *map)
{
	if (map->size > 2 && map->l_len > 2)
	{
		if (map->size > 4 || map->l_len > 4)
			return ;
	}
	ft_putstr_fd("Error\nO tamanho minimo para este \
					mapa nao foi respeitado\n", 1);
	destroy_map(map);
	exit(EINVAL);
}

void	map_boundaries_ok(t_lines *map)
{
	int	checker;
	int	index;

	check_map_size(map);
	index = 0;
	checker = 0;
	while (index < map->size)
	{
		if (index == 0 || index == map->size - 1)
			line_has_only_blocks(map->lines[index], map);
		else
			line_has_boundary_blocks(map->lines[index], map->l_len, map);
		index++;
	}
}
