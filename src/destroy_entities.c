/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_entities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:42:55 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 19:02:11 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	destroy_entities(t_entity **ent_ar)
{
	int	i;

	i = 0;
	while (ent_ar[i])
	{
		destroy_entity(ent_ar[i]);
		i++;
	}
	free(ent_ar);
	ent_ar = NULL;
}
