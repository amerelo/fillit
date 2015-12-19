/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:16:53 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:16:55 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puttab(char **tab)
{
	int x;
	int y;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			ft_putchar(tab[y][x]);
			x++;
		}
		y++;
	}
	ft_putchar('\n');
}