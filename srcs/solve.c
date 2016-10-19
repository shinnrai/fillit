/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:17:22 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/11 16:36:36 by dbanifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	setup(t_tetriminos *tetrs, int quantity)
{
	g_i = -1;
	g_dim = quantity * 4;
	g_quantity = quantity;
	g_mdim = g_dim;
	g_cdim = 0;
	g_min_map = NULL;
	g_tetrs = tetrs;
	g_map = (char **)malloc(sizeof(char *) * g_dim);
	while (++g_i < g_dim)
	{
		g_j = -1;
		g_map[g_i] = (char *)malloc(sizeof(char) * g_dim);
		while (++g_j < g_dim)
			g_map[g_i][g_j] = '.';
	}
}

void	save_to_min(int dim)
{
	if (g_min_map)
	{
		g_i = -1;
		while (++g_i < g_mdim)
			free(g_min_map[g_i]);
		free(g_min_map);
	}
	g_mdim = dim;
	g_min_map = (char **)malloc(sizeof(char *) * g_mdim);
	g_i = -1;
	while (++g_i < g_mdim)
	{
		g_j = -1;
		g_min_map[g_i] = (char *)malloc(sizeof(char) * (g_mdim + 1));
		while (++g_j < g_mdim)
			g_min_map[g_i][g_j] = g_map[g_i][g_j];
		g_min_map[g_i][g_mdim] = '\0';
	}
}

void	find_min(int number, int crows, int ccolumns)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_mdim)
	{
		j = -1;
		while (++j < g_mdim)
			if (can_insert(i, j, g_tetrs[number]))
			{
				g_crows = crows;
				g_ccolumns = ccolumns;
				insert_tetriminos(i, j, number);
				g_cdim = (g_ccolumns > g_crows) ? g_ccolumns : g_crows;
				if (number + 1 == g_quantity)
				{
					if (g_cdim < g_mdim || g_min_map == NULL)
						save_to_min(g_cdim);
				}
				else
					find_min(number + 1, g_crows, g_ccolumns);
				delete_tetriminos(i, j, g_tetrs[number]);
			}
	}
}

char	**solve(t_tetriminos *tetrs, int quantity)
{
	setup(tetrs, quantity);
	find_min(0, 0, 0);
	return (g_min_map);
}
