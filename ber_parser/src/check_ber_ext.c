/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:58:19 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/16 17:23:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <berparser.h>

int	check_ber_ext(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len == 0 || len < 4)
	{
		errno = EINVAL;
		ft_putstr_fd("Error\nArgumento invalido.\n", 1);
		exit(EINVAL);
	}
	if (path[len - 4] == '.' && path[len - 3] == 'b' && \
		path[len - 2] == 'e' && path[len - 1] == 'r')
		return (1);
	else
	{
		errno = EINVAL;
		ft_putstr_fd("Error\nExtensao Invalida\n", 1);
		exit(EINVAL);
	}
	return (0);
}
