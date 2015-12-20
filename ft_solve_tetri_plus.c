/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tetri_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:26:08 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:26:10 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_solve_tetri_plus(t_tetri *mainlist, char **final, int y, int x)
{
	t_tetri *tmp;

	if ((tmp = mainlist) != NULL && ft_test_isvalid(tmp))
		return (1);
	while (tmp != NULL)
	{
		while (final[y])
		{
			if (tmp->is_valid == 0 && ft_test_2(tmp, final, y, x))
			{
				ft_place(tmp, final, y, x);
				if (ft_solve_tetri_plus(mainlist, final, y, x))
					return (1);
				else
					ft_unplace(tmp, final, y, x);
			}
			x = (final[y][x] == '\n' && final[y]) ? -1 : x + 1;
			y = (final[y][x] == '\n' && final[y]) ? y + 1 : y;
		}
		x = 0;
		y = 0;
		tmp = tmp->next;
	}
	return (0);
}
