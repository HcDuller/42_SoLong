/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_just_one_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:46:12 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 13:51:01 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	has_just_one_player(char *map)
{
	int		players;
	char	*ptr;

	players = 0;
	ptr = map;
	while (*map)
		if ((char)*(map++) == '3')
			players++;
	if (players != 1)
	{
		if (players > 1)
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Mais do que 1 jogador foi especificado.\n", 1);
		}
		if (players < 1)
		{
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Menos do que 1 jogador foi especificado.\n", 1);
		}
		free(ptr);
		exit(EINVAL);
		return (0);
	}
	return (1);
}
