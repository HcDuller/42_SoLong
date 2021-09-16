/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:10:10 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/16 17:15:20 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	map_is_big_enough(char *map)
{
	int	l;

	l = ft_strlen(map);
	if (l < 15)
	{
		free(map);
		map = (NULL);
		ft_putstr_fd("Error\nMapa de tamanho insuficiente.", 1);
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}
