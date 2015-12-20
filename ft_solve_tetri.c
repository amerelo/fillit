/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:26:08 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:26:10 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_solve_tetri(t_tetri *mainlist, int size)
{
	int		x;
	int		y;
	char	**final_carre;
	t_tetri	*tmp;

	x = 0;
	y = 0;
	tmp = mainlist;
	final_carre = ft_create_table(size);
	if (ft_solve_tetri_plus(mainlist, final_carre, y, x))
		ft_puttab(final_carre);
	else
	{
		free(final_carre);
		while (mainlist)
		{
			mainlist->is_valid = 0;
			mainlist = mainlist->next;
		}
		return (ft_solve_tetri(tmp, (size + 1)));
	}
	return (1);
}
