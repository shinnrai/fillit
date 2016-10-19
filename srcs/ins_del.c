/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:11:43 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/11 16:36:16 by dbanifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		can_insert(int row, int column, t_tetriminos tetr)
{
	g_i = 0;
	g_n = 0;
	while (g_n != 4 && g_i <= 12)
	{
		if (BIT(g_i) & (int)tetr)
		{
			if (row + g_i / 4 >= g_mdim || column + g_i % 4 >= g_mdim ||
				g_map[row + g_i / 4][column + g_i % 4] != '.')
				return (0);
			g_n++;
		}
		g_i++;
	}
	return (1);
}

void	insert_tetriminos(int row, int column, int number)
{
	g_i = 0;
	g_n = 0;
	while (g_n != 4 && g_i <= 12)
	{
		if (BIT(g_i) & (int)g_tetrs[number])
		{
			g_map[row + g_i / 4][column + g_i % 4] = 'A' + number;
			if (g_crows < row + g_i / 4 + 1)
				g_crows = row + g_i / 4 + 1;
			if (g_ccolumns < column + g_i % 4 + 1)
				g_ccolumns = column + g_i % 4 + 1;
			g_n++;
		}
		g_i++;
	}
}

void	delete_tetriminos(int row, int column, t_tetriminos tetr)
{
	g_i = 0;
	g_n = 0;
	while (g_n != 4 && g_i <= 12)
	{
		if (BIT(g_i) & (int)tetr)
		{
			g_map[row + g_i / 4][column + g_i % 4] = '.';
			g_n++;
		}
		g_i++;
	}
}
