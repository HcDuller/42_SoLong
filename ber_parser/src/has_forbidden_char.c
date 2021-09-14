/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_forbidden_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:15:33 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 13:50:45 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	has_forbidden_char(char *map)
{
	char	*ptr;

	ptr = map;
	while (*map)
	{
		if ((char)*map != '\n')
		{
			if (!((char)*map >= 48 && (char)*map <= 52))
			{
				ft_putstr_fd("Error\nExistem caracteres", 1);
				ft_putstr_fd(" nao permitidos neste mapa.\n", 1);
				free(ptr);
				exit(EINVAL);
				return (1);
			}
		}
		map++;
	}
	return (0);
}
