/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:19:06 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:19:08 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_table(int size)
{
	int		size_cube;
	int		x;
	int		y;
	char	**final_tab;

	size_cube = 2;
	while (ft_power_x(size_cube) < (size * 4))
		size_cube++;
	final_tab = (char **)ft_memalloc(sizeof(char *) * (size_cube + 1));
	x = 0;
	while (x < size_cube)
	{
		final_tab[x] = (char *)ft_memalloc(sizeof(char ) * (size_cube + 2));
		y = 0;
		while (y < size_cube)
		{
			final_tab[x][y] = '.';
			y++;
		}
		final_tab[x][y] = '\n';
		x++;
	}
	return (final_tab);
}
