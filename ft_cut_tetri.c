/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:21:22 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:21:23 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*ft_cut_tetri(char *tetri)
{
	int			x;
	t_piece		*p;
	t_piece		*tmp;

	p = NULL;
	x = 0;
	while (tetri[x] != '\0')
	{
		if (tetri[x] == '#')
		{
			tmp = (t_piece *)malloc(sizeof(t_piece));
			tmp->x = x % 5;
			tmp->y = x / 5;
			tmp->next = NULL;
			tmp->prev = p;
			p = (p == NULL ? tmp : p);
			p->next = (p == NULL ? NULL : tmp);
			p = (p == NULL ? p : p->next);
		}
		x++;
	}
	while (p->prev)
		p = p->prev;
	p = ft_cut_tetri_plus(p);
	return (p);
}
