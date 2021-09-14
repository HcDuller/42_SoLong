/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:16:50 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/01 16:44:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	line_size(char *str)
{
	int	size;

	size = 0;
	while (*str && *str != '\n')
	{
		size++;
	}
	return (size);
}