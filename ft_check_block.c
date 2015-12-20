/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matirell <matirell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 21:15:50 by matirell          #+#    #+#             */
/*   Updated: 2015/12/19 21:15:53 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_block(char *str)
{
	int x;
	int count_chars;
	int count_diezes;
	int t;

	t = 0;
	x = -1;
	count_chars = 0;
	count_diezes = 0;
	while (str[++x])
	{
		if ((x == 9 || x == 14 || x == 19) && str[x - 5] != '\n')
			return (0);
		else if (str[x] == '#' && (str[x - 1] == '#' || str[x + 1] == '#' ||
		str[x + 5] == '#' || str[x - 5] == '#'))
			count_diezes++;
		if (str[x] == '#' && ft_check_block_plus(str, x) && !t--)
			count_diezes++;
		if (str[x] == '.')
			count_chars++;
	}
	if (count_chars == 12 && count_diezes == 5)
		return (1);
	return (0);
}
