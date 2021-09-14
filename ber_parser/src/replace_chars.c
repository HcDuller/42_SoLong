/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:11:40 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/01 16:44:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

void	replace_chars(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == 'C')
			(*str)[i] = '2';
		if ((*str)[i] == 'P')
			(*str)[i] = '3';
		if ((*str)[i] == 'E')
			(*str)[i] = '4';
		i++;
	}
}
