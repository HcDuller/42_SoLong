/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_distinct_line_sizes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:12:10 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 14:02:43 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	has_distinct_line_sizes(t_lines *map_lines)
{
	int	l_index;
	int	l_len;

	l_index = 0;
	l_len = ft_strlen((*map_lines).lines[l_index]);
	while ((*map_lines).lines[l_index])
	{
		if (l_index > 0)
		{
			if (ft_strlen((*map_lines).lines[l_index]) != (size_t)l_len)
			{
				(*map_lines).l_len = 0;
				destroy_map(map_lines);
				ft_putstr_fd("Error\nO mapa não é um retangulo.\n", 1);
				exit(EINVAL);
				return (1);
			}
		}
		l_index++;
	}
	(*map_lines).l_len = l_len;
	return (0);
}
