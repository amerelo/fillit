/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_tetri_plus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:20:18 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:20:20 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*ft_cut_tetri_plus(t_piece *p)
{
	int xtmp;
	int ytmp;

	ytmp = p->y;
	xtmp = p->x;
	while (p->next != NULL)
	{
		ytmp = (ytmp > p->y ? p->y : ytmp);
		xtmp = (xtmp > p->x ? p->x : xtmp);
		p = p->next;
	}
	ytmp = (ytmp > p->y ? p->y : ytmp);
	xtmp = (xtmp > p->x ? p->x : xtmp);
	while (p->prev != NULL)
	{
		p->y -= ytmp;
		p->x -= xtmp;
		p = p->prev;
	}
	p->y -= ytmp;
	p->x -= xtmp;
	return (p);
}
