/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:01:57 by amerelo           #+#    #+#             */
/*   Updated: 2015/12/13 18:09:27 by amerelo          ###   ########.fr       */
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
		if (str[x] == '.')
			count_chars++;
	}
	if (count_chars == 12 && count_diezes == 5)
		return (1);
	return (0);
}



void ft_puttab(char **tab) // test...................................................................................................
{
	int x;
	int y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while(tab[x][y])
		{
			ft_putchar(tab[x][y]);
			y++;
		}
		x++;
	}
	ft_putchar('\n');
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


char **create_tableau(int size)
{
	int size_cube;
	int x;
	int y;
	int len;
	char **final_tab;

	size_cube = 2;
	while (power_x(size_cube) < (size * 4))
		size_cube++;
	final_tab = (char **)ft_memalloc(sizeof(char *) * (size_cube + 1));
	x = 0;
	while (x < size_cube )
	{
		final_tab[x] = (char *)ft_memalloc(sizeof(char ) * (size_cube + 2));

		y = 0;
		while (y < size_cube )
		{
			final_tab[x][y] = '.';
			y++;
		}
		final_tab[x][y] = '\n';
		x++;
	}
	return (final_tab);
}

void super_putendl(char *mainlist, t_tetri *tetri) // test.................................................................................
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











t_piece *cut_tetri_plus(t_piece *p)
{
	int xtmp;
	int ytmp;

	ytmp = p->y;
	xtmp = p->x;
	while (p->next != NULL)
	{
		ytmp = (ytmp >  p->y ? p->y : ytmp);
		xtmp = (xtmp >  p->x ? p->x : xtmp);
		p = p->next;
	}
		ytmp = (ytmp >  p->y ? p->y : ytmp);
		xtmp = (xtmp >  p->x ? p->x : xtmp);
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


t_piece *cut_tetri(char *tetri)
{
	int 		x;
	t_piece		*p;
	t_piece 	*tmp;

	p = NULL;
	x = 0;
	while (tetri[x] != '\0')
	{
		if(tetri[x] == '#')
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
	p = cut_tetri_plus(p);
	return (p);
}




t_tetri	*create_list_element(char  *tetriminos, int x)
{
	t_tetri *new_tetri;

	new_tetri = (t_tetri *)malloc(sizeof(t_tetri));
	if (!new_tetri)
		return (NULL);

	new_tetri->p = cut_tetri(tetriminos);
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












int  test_2(t_tetri *mainlist, char **final_carre, int x, int y)
{

	while (mainlist->p->next != NULL)
	{
		ft_putendl("Hola");
		if (final_carre[y + mainlist->p->y][x + mainlist->p->x]  == '.')
		{
					ft_putendl("A");
			mainlist->p = mainlist->p->next;
					ft_putendl("B");
		}
		else
		{
			ft_putendl("1");
			while (mainlist->p->prev)
				mainlist->p = mainlist->p->prev;
			ft_putendl("2");
			return (0);
		}
	}
	ft_putendl("Hola");
	if (final_carre[y + mainlist->p->y][x + mainlist->p->x] )
	{
		ft_putendl("TY");
		while (mainlist->p->prev)
			mainlist->p = mainlist->p->prev;
		ft_putendl("VY");
		return (1);
	}
	else
	{
		ft_putendl("x");
		while (mainlist->p->prev)
			mainlist->p = mainlist->p->prev;
		ft_putendl("y");
		return (0);
	}
}


void test(t_tetri *mainlist, char **final_carre, int x, int y)
{
	while (mainlist->p->next != NULL)
	{

		final_carre[y + mainlist->p->y][x + mainlist->p->x] =
		 mainlist->tetri_nuber + 'A';
		mainlist->p = mainlist->p->next;
	}
	final_carre[y + mainlist->p->y][x + mainlist->p->x]  =
	 mainlist->tetri_nuber + 'A';
	while (mainlist->p->prev)
		mainlist->p = mainlist->p->prev;
}

	




int solve_tetri_plus(t_tetri *mainlist, char **final_carre)
{
	int x;
	int y;


	y = 0;
	while (final_carre[y]!= '\0' && mainlist != NULL)
	{
		x = 0;	
		while (final_carre[y][x] != '\0' && mainlist != NULL)
		{
			if (test_2(mainlist, final_carre, x, y))
			{
				test(mainlist, final_carre, x, y);
				mainlist = mainlist->next;
			}
			x++;
		}
		y++;
	}
	if (mainlist == NULL)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


void solve_tetri(t_tetri *mainlist, int size)
{
	int x;
	int y;
	char **final_carre;
	t_tetri *tmp;

	tmp = mainlist;	
	final_carre = create_tableau(size);
	if (solve_tetri_plus(mainlist, final_carre))
		ft_puttab(final_carre);
	else
	{
		free (final_carre);
		solve_tetri(tmp, (size + 1));
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
		while (i < 20 && str[i + x] && (str[i + x] == '.' || str[i + x] == '#'
		 || str[i + x] == '\n'))
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

	solve_tetri(head, (x % 20 + 1));
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
			if (r == -1 || !check_tetri(buf))
			{
				ft_putendl("error");
				close(fi);
				return (-1);
			}
			close(fi);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	return (0);
}
