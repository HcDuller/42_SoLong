/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:14:14 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/01 16:44:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	count_lines(char *str)
{
	int	lines;

	lines = 1;
	while (*str)
	{
		if (*str++ == '\n')
			lines++;
	}
	return (lines);
}
