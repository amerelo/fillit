/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:14:47 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:14:50 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_block_plus(char *str, int x)
{
	if (str[x - 1] == '#' && str[x - 5] == '#')
		return (1);
	else if (str[x + 1] == '#' && str[x - 5] == '#')
		return (1);
	else if (str[x + 1] == '#' && str[x + 5] == '#')
		return (1);
	else if (str[x - 1] == '#' && str[x + 5] == '#')
		return (1);
	else if (str[x - 1] == '#' && str[x + 1] == '#')
		return (1);
	else if (str[x - 5] == '#' && str[x + 5] == '#')
		return (1);
	return (0);
}
