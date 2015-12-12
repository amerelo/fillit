/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:01:57 by amerelo           #+#    #+#             */
/*   Updated: 2015/12/10 05:49:36 by amerelo          ###   ########.fr       */
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

int	check_block(char *str)
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
		else if (str[x] == '#' && (str[x - 1] == '#' || str[x + 1] == '#'||
		str[x + 5] == '#' || str[x - 5] == '#'))
			count_diezes++;
		if (str[x] == '#' && check_block_plus(str, x) &&  !t--)
			count_diezes++;
		count_chars++;
	}
	if (count_chars == 20 && count_diezes == 5)
		return (1);
	return (0);
}


int power_x(int x)
{
	int y;
	int tmp;

	y = x;
	tmp = 1;
	while (tmp < y)
	{
		x += y;
		tmp++;
	}
	return (x);
}



char *create_tableau(int size)
{
	int x;
	int len;
	int i;
	int tmp;
	char *final_tab;

	x = 2;
	i = 0;
	while (power_x(x) < (size * 4))
		x++;
	tmp = (power_x(x) + x);
	final_tab = (char *)ft_memalloc(sizeof(char) * (tmp + 1));
	while (i < tmp)
	{
		len = x;
		while (len--)
		{
			final_tab[i] = '.';
			i++;
		}
		final_tab[i] = '\n';
		i++;
	}
	ft_putendl(final_tab);
	return (final_tab);
}




/* typedef struct		su_list
{
	
	sruct piece 	*p;
	int				tetri_nuber;
	struct su_list	*next;
}					t_tetri;


sruct piece
{
	int	x;
	int	y;
	sruct piece *next;;
} */


char *cut_tetri(char *tetri)
{
	int i;
	int x;
	int count_diezes;
	char *tmp;

	i = 0;
	x = 0;
	count_diezes = 0;
	tmp = (char *)ft_memalloc(sizeof(char) * 9);
	while (tetri[i] && count_diezes < 4)
	{
		if (tetri[i] == '#' && (tetri[i + 4] == '#' || tetri[i + 9] == '#') && count_diezes == 0)
		{
			tmp[x] = '.';
			x++;
			tmp[x] = '#';
			x++;
			count_diezes++;
		}
		else if (tetri[i] == '#' && tetri[i - 6] == '#')
		{
			tmp[x] = '.';
			x++;
			tmp[x] = '#';
			x++;
			count_diezes++;
		}
		else if (tetri[i] == '#')
		{
			tmp[x] = '#';
			x++;
			count_diezes++;
		}
		else if (tetri[i] == '\n')
		{
			tmp[x] = '\n';
			x++;
		}

		i++;
	}
//		tmp[x] = '\n';
	return (tmp);
}

void super_putendl(char *mainlist, t_tetri *tetri)
{
	int i;

	i = 0;
	while (mainlist[i])
	{
	 if (mainlist[i] == '#')
	 	ft_putchar(tetri->tetri_nuber + 'A');
	 else
	 	ft_putchar(mainlist[i]);
	 i++;
	}
	ft_putchar('\n');
}

t_tetri	*create_list_element(char  *tetriminos, int x)
{
	t_tetri *new_tetri;

	new_tetri = (t_tetri *)malloc(sizeof(t_tetri));
	if (!new_tetri)
		return (NULL);
	new_tetri->tetri = cut_tetri(tetriminos);
	new_tetri->tetri_nuber = x;
	new_tetri->next = NULL;
	return (new_tetri);
}

t_tetri *add_on_list(t_tetri *head, t_tetri *l_tmp, int x)
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


//int test_plus(t_tetri *mainlist, int *final_carre)
//{
//}

void test(t_tetri *mainlist, int carre)
{
	int x;
	int i;
	char *final_carre;

	/*
	
	i = 0;
	x = 0;
	while (mainlist->tetri[i])
	{	
		while (mainlist->tetri[x] != '#')
			x++;
		if (mainlist->tetri[i] == '#')
		{

		}
		i++;
	}*/

	while (mainlist != NULL)
	{
		x++;
		super_putendl(mainlist->tetri, mainlist);
		mainlist = mainlist->next;
	}
}

int		check_tetri(char *str)
{
	int			x;
	int			i;
	char		*tmp;
	t_tetri 	*head;
	t_tetri		*l_tmp;

	x = 0;
	while(str[x])
	{
		if (!(tmp = (char *)ft_memalloc(sizeof(char) * 21)))
			return (0);
		i = 0;
		while (i < 20 && str[i + x] && (str[i + x] == '.' || str[i + x] == '#' ||
		 str[i + x] == '\n'))
		{
			tmp[i] = str[i + x];
			i++;
		}
		x += i;
		if(i != 20 || !(check_block(tmp)))
			return (0);
		if (str[x] == '\n' && str[x + 1] != '.' && str[x + 1] != '#')
			return (0);
		l_tmp = create_list_element(tmp, (x % 20));
		head = add_on_list(head	, l_tmp, (x % 20));
		x++;
	}
	x--;
	test (head, (x % 20 + 1) );
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
				ft_putendl("error");
				close(fi);
				return (-1);
			}
			close(fi);
		}
	}
	return (0);
}
