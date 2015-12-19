/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_on_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:22:51 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:22:53 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_add_on_list(t_tetri *head, t_tetri *l_tmp, int x)
{
	t_tetri *tmp;

	if (x != 0)
	{
		tmp = head;
		while (head->next != NULL)
			head = head->next;
		head->next = (t_tetri *)malloc(sizeof(t_tetri));
		head->next = l_tmp;
		return (tmp);
	}
	else
		head = l_tmp;
	return (head);
}
