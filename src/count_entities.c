/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:50:37 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/04 18:10:18 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	count_entities(char **lines, char c)
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
			if ((char)(lines[l_i])[c_i] == c)
				counter++;
			c_i++;
		}	
		l_i++;
	}
	return (counter);
}
