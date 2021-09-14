/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_one_or_more_of.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:46:51 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/06 13:51:35 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	has_one_or_more_of(char *map, char obj)
{
	int		counter;
	char	*ptr;

	counter = 0;
	ptr = map;
	while (*map)
		if ((char)*(map++) == obj)
			counter++;
	if (counter < 1)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Nao ha 1 ou mais coletaveis e/ou saidas.\n", 1);
		free(ptr);
		exit(EINVAL);
		return (0);
	}
	return (1);
}
