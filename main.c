/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:01:57 by amerelo           #+#    #+#             */
/*   Updated: 2015/12/04 15:02:01 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int check_block_plus(char *str, int x)
{
	if (str[x - 1] == '#' && str[x - 5] == '#')
		return (1);
	else if (str[x + 1] == '#' && str[x - 5] == '#')
		return (1);
	else if (str[x + 1] == '#' && str[x + 5] == '#')
		return(1);
	else if (str[x - 1] == '#' && str[x + 5] == '#')
		return (1);
	else if (str[x - 1] == '#' && str[x + 1] == '#')
		return(1);
	else if (str[x - 5] == '#' && str[x + 5] == '#')
		return (1);
	return (0);
}

int		check_block(char *str)
{
	int x;
	int count_chars;
	int count_diezes;
	int t;

	t = 1;
	x = -1;
	count_chars = 0;
	count_diezes = 0;
	while (str[++x])
	{
		if ((x == 9 || x == 14 || x == 19) && str[x - 5] != '\n')
			return (0);
		else if (str[x] == '#' && (str[x - 1] == '#' || str[x + 1] == '#'||
		str[x + 5] == '#' || str[x - 5] == '#'))
			count_diezes++;
		if (str[x] == '#' && check_block_plus(str, x) &&  !t--)
			count_diezes++;
		count_chars++;
	}
	ft_putnbr(count_diezes);
	if (count_chars == 20 && count_diezes == 5)
		return (1);
	return (0);
}


/* typedef struct		s_list
{
	char            *tetri;
	int				tetri_nuber;
	struct s_list	*next;
}					t_tetri;

t_list	*save_tetri(char tmp, int x)
{
	t_tetri *tetri;


}
*/

int		check_tetri(char *str)
{
	int x;
	int i;
	char *tmp;

	x = 0;
	while(str[x])
	{
		if (!(tmp = (char *)ft_memalloc(sizeof(char) * 21)))
			return (0);
		i = 0;
		while (i < 20 && str[i + x] && (str[i + x] == '.' || str[i + x] == '#' || str[i + x] == '\n'))
		{
			tmp[i] = str[i + x];
			i++;
		}
		x += i;
		if(i != 20 || !(check_block(tmp)))
		{
			ft_putendl("ERROR");
			return (0);
		}
	//	ft_putnbr(x % 20);
		ft_putchar('\n');
		ft_putendl(tmp); //  save_tetri(tmp, (x % 20))
		if (str[x] == '\n' && str[x + 1] != '.' && str[x + 1] != '#')
			return (0);
		x++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int 	fi;
	char	buf[1025];
	int		r;


	if (ac == 2)
	{
		fi = open(av[1], O_RDONLY);
		if (fi > 0)
		{
			r = read(fi, buf, 1024);
			buf[r] = '\0';
			if (!check_tetri(buf))
			{
				ft_putendl("ERROR");
				close(fi);
				return (-1);
			}
			close(fi);
		}
	}
	return (0);
}