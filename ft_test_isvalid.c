/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_isvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:29:56 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:29:59 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_test_isvalid(t_tetri *tmp)
{
	while (tmp != NULL)
	{
		if (tmp->is_valid == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
