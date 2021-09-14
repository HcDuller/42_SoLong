/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:47:29 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/01 16:44:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

void	free_lines(t_lines map_lines)
{
	void	*aux;
	int		len;

	len = map_lines.size;
	while (len > 0)
	{
		aux = map_lines.lines[len - 1];
		free(map_lines.lines[len - 1]);
		aux = NULL;
		len--;
	}
	aux = map_lines.lines;
	free(map_lines.lines);
	map_lines.lines = NULL;
}
