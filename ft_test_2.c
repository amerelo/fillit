/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:31:23 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:31:24 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_test_2(t_tetri *mainlist, char **final_carre, int y, int x)
{
	while (mainlist->p->next != NULL)
	{
		if (final_carre[y + mainlist->p->y] && final_carre
			[y + mainlist->p->y][x + mainlist->p->x] == '.')
			mainlist->p = mainlist->p->next;
		else
		{
			while (mainlist->p->prev)
				mainlist->p = mainlist->p->prev;
			return (0);
		}
	}
	if (final_carre[y + mainlist->p->y] && final_carre
		[y + mainlist->p->y][x + mainlist->p->x] == '.')
	{
		while (mainlist->p->prev)
			mainlist->p = mainlist->p->prev;
		return (1);
	}
	else
	{
		while (mainlist->p->prev)
			mainlist->p = mainlist->p->prev;
		return (0);
	}
}