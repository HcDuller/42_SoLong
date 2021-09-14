/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:49:26 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 00:45:59 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	int	count_entities_2(char **lines)
{
	int	l_i;
	int	c_i;
	int	counter;

	l_i = 0;
	counter = 0;
	while (lines[l_i] != NULL)
	{
		c_i = 0;
		while ((lines[l_i])[c_i])
		{
			c_i++;
			counter++;
		}	
		l_i++;
	}
	return (counter);
}

t_entity	**fill_entities(t_lines map)
{
	t_entity	**entities;
	int			e_i;
	int			l_i;
	int			c_i;

	entities = ft_calloc(count_entities_2(map.lines) + 1, sizeof(t_entity *));
	l_i = 0;
	e_i = 0;
	while (map.lines[l_i])
	{
		c_i = 0;
		while (map.lines[l_i][c_i])
		{
			entities[e_i] = new_entity(c_i, l_i, (char)map.lines[l_i][c_i]);
			e_i++;
			c_i++;
		}
		l_i++;
	}
	return (entities);
}
