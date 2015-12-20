/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:23:47 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:23:51 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_create_list_element(char *tetriminos, int x)
{
	t_tetri *l_tmp;

	l_tmp = (t_tetri *)malloc(sizeof(t_tetri));
	if (!l_tmp)
		return (NULL);
	l_tmp->p = ft_cut_tetri(tetriminos);
	l_tmp->tetri_number = x;
	l_tmp->is_valid = 0;
	l_tmp->next = NULL;
	return (l_tmp);
}
