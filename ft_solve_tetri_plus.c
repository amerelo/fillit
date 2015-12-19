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

int ft_solve_tetri_plus(t_tetri *mainlist, char **final_carre, int y, int x)
{
	t_tetri *tmp;

	if ((tmp = mainlist) != NULL && ft_test_isvalid(tmp))
		return (1);
	while (tmp != NULL)
	{
		while (final_carre[y])
		{
			if (tmp->is_valid == 0 && ft_test_2(tmp, final_carre, y, x))
			{
				ft_place(tmp, final_carre, y, x);
				if (ft_solve_tetri_plus(mainlist, final_carre, y, x))
					return (1);
				else
					ft_unplace(tmp, final_carre, y, x);
			}
			x = (final_carre[y][x] == '\n' && final_carre[y]) ? -1 : x + 1;
			y = (final_carre[y][x] == '\n' && final_carre[y]) ? y + 1 : y;
		}
		x = 0;
		y = 0;
		tmp = tmp->next;
	}
	return (0);
}
