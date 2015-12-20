/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:54:17 by amerelo           #+#    #+#             */
/*   Updated: 2015/12/20 15:42:51 by matirell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_piece
{
	int				x;
	int				y;
	struct s_piece	*next;
	struct s_piece	*prev;
}					t_piece;

typedef	struct		s_list
{
	t_piece			*p;
	int				tetri_number;
	int				is_valid;
	struct s_list	*next;
}					t_tetri;

typedef struct		s_tmp
{
	int			x;
	int			i;
	int			y;
	char		*tmp;
	t_tetri		*head;
	t_tetri		*l_tmp;
}					t_tmp;

t_tetri				*ft_add_on_list(t_tetri *head, t_tetri *l_tmp, int x);
int					ft_check_block(char *str);
int					ft_check_block_plus(char *str, int x);
int					ft_check_tetri(char *str);
t_tetri				*ft_create_list_element(char *tetriminos, int x);
char				**ft_create_table(int size);
t_piece				*ft_cut_tetri(char *tetri);
t_piece				*ft_cut_tetri_plus(t_piece *p);
void				ft_place(t_tetri *mainlist, char \
					**final_carre, int y, int x);
int					ft_power_x(int x);
void				ft_puttab(char **tab);
int					ft_solve_tetri(t_tetri *mainlist, int size);
int					ft_solve_tetri_plus(t_tetri *mainlist, char **final, \
					int y, int x);
int					ft_test_2(t_tetri *mainlist, char **final_carre, \
					int y, int x);
int					ft_test_isvalid(t_tetri *tmp);
void				ft_unplace(t_tetri *mainlist, char **final_carre, \
					int y, int x);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
#endif
