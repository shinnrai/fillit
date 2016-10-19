/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 13:44:44 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/13 14:35:28 by dbanifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
**	I_HOR:15	I_VER:4369
**		####		#...
**		....		#...
**		....		#...
**		....		#...
**
**	O:51
**		##..
**		##..
**		....
**		....
**
**	T_UP:39		T_RIGHT:562	T_DOWN:114	T_LEFT:305
**		###.		.#..		.#..		#...
**		.#..		##..		###.		##..
**		....		.#..		....		#...
**		....		....		....		....
**
**	J_UP:802	J_RIGHT:113	J_DOWN:275	J_LEFT:71
**		.#..		#...		##..		###.
**		.#..		###.		#...		..#.
**		##..		....		#...		....
**		....		....		....		....
**
**	L_UP:785	L_RIGHT:23	L_DOWN:547	L_LEFT:116
**		#...		###.		##..		..#.
**		#...		#...		.#..		###.
**		##..		....		.#..		....
**		....		....		....		....
**
**	S_HOR:54		S_VER:561
**		.##.		#...
**		##..		##..
**		....		.#..
**		....		....
**
**	Z_HOR:99	Z_VER:306
**		##..		.#..
**		.##.		##..
**		....		#...
**		....		....
**
**	TETRIMINOS:
**		0	1	2	3
**		4	5	6	7
**		8	9	10	11
**		12	13	14	15
*/

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BIT(i) 1 << (i)
# define BUFF_SIZE 1024

typedef enum	e_tetriminos
{
	I_HOR = BIT(0) | BIT(1) | BIT(2) | BIT(3),
	I_VER = BIT(0) | BIT(4) | BIT(8) | BIT(12),
	O = BIT(0) | BIT(1) | BIT(4) | BIT(5),
	T_UP = BIT(0) | BIT(1) | BIT(2) | BIT(5),
	T_RIGHT = BIT(1) | BIT(4) | BIT(5) | BIT(9),
	T_DOWN = BIT(1) | BIT(4) | BIT(5) | BIT(6),
	T_LEFT = BIT(0) | BIT(4) | BIT(5) | BIT(8),
	J_UP = BIT(1) | BIT(5) | BIT(8) | BIT(9),
	J_RIGHT = BIT(0) | BIT(4) | BIT(5) | BIT(6),
	J_DOWN = BIT(0) | BIT(1) | BIT(4) | BIT(8),
	J_LEFT = BIT(0) | BIT(1) | BIT(2) | BIT(6),
	L_UP = BIT(0) | BIT(4) | BIT(8) | BIT(9),
	L_RIGHT = BIT(0) | BIT(1) | BIT(2) | BIT(4),
	L_DOWN = BIT(0) | BIT(1) | BIT(5) | BIT(9),
	L_LEFT = BIT(2) | BIT(4) | BIT(5) | BIT(6),
	S_HOR = BIT(1) | BIT(2) | BIT(4) | BIT(5),
	S_VER = BIT(0) | BIT(4) | BIT(5) | BIT(9),
	Z_HOR = BIT(0) | BIT(1) | BIT(5) | BIT(6),
	Z_VER = BIT(1) | BIT(4) | BIT(5) | BIT(8),
}				t_tetriminos;

char			**g_min_map;
char			**g_map;
t_tetriminos	*g_tetrs;
int				g_dim;
int				g_mdim;
int				g_cdim;
int				g_quantity;
int				g_i;
int				g_j;
int				g_n;
int				g_crows;
int				g_ccolumns;
int				g_start;
int				g_nb;
char			*g_check;

int				valid_tetr(char *str, int len);
int				create_array(char *str);
int				ft_strlen(char *str);
int				can_insert(int row, int column, t_tetriminos tetr);
void			insert_tetriminos(int row, int column, int number);
void			delete_tetriminos(int row, int column, t_tetriminos tetr);
void			setup(t_tetriminos *tetrs, int quantity);
void			save_to_min(int dim);
void			find_min(int number, int crows, int ccolumns);
char			**solve(t_tetriminos *tetrs, int quantity);
void			print(int dim);

#endif
