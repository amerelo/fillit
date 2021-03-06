/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:24:35 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:24:38 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place(t_tetri *mainlist, char **final_carre, int y, int x)
{
	mainlist->is_valid = 1;
	while (mainlist->p->next != NULL)
	{
		final_carre[y + mainlist->p->y][x + mainlist->p->x] =
		mainlist->tetri_number + 'A';
		mainlist->p = mainlist->p->next;
	}
	final_carre[y + mainlist->p->y][x + mainlist->p->x] =
	mainlist->tetri_number + 'A';
	while (mainlist->p->prev)
		mainlist->p = mainlist->p->prev;
}
