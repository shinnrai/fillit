/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:50:40 by ofedorov          #+#    #+#             */
/*   Updated: 2016/10/17 14:14:10 by dbanifat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetriminos		determine_tetr(int nb)
{
	t_tetriminos	tetr;

	tetr = 0;
	tetr = (nb == (int)I_HOR) ? I_HOR : tetr;
	tetr = (nb == (int)I_VER) ? I_VER : tetr;
	tetr = (nb == (int)O) ? O : tetr;
	tetr = (nb == (int)T_UP) ? T_UP : tetr;
	tetr = (nb << 1 == (int)T_RIGHT) ? T_RIGHT : tetr;
	tetr = (nb << 1 == (int)T_DOWN) ? T_DOWN : tetr;
	tetr = (nb == (int)T_LEFT) ? T_LEFT : tetr;
	tetr = (nb << 1 == (int)J_UP) ? J_UP : tetr;
	tetr = (nb == (int)J_RIGHT) ? J_RIGHT : tetr;
	tetr = (nb == (int)J_DOWN) ? J_DOWN : tetr;
	tetr = (nb == (int)J_LEFT) ? J_LEFT : tetr;
	tetr = (nb == (int)L_UP) ? L_UP : tetr;
	tetr = (nb == (int)L_RIGHT) ? L_RIGHT : tetr;
	tetr = (nb == (int)L_DOWN) ? L_DOWN : tetr;
	tetr = (nb << 2 == (int)L_LEFT) ? L_LEFT : tetr;
	tetr = (nb << 1 == (int)S_HOR) ? S_HOR : tetr;
	tetr = (nb == (int)S_VER) ? S_VER : tetr;
	tetr = (nb == (int)Z_HOR) ? Z_HOR : tetr;
	tetr = (nb << 1 == (int)Z_VER) ? Z_VER : tetr;
	return (tetr);
}

int					valid_tetr(char *str, int len)
{
	char			c;

	if (g_i + g_j >= len)
		return (-1);
	c = str[g_i + g_j];
	if ((g_j % 5 == 4 && c != '\n') ||
		(g_j % 5 != 4 && c != '#' && c != '.'))
		return (-1);
	if (c == '#' && g_start == -1)
		g_start = 0;
	if (c == '#' && g_start == 4)
		return (-1);
	if (g_j % 5 != 4 && 0 <= g_start && g_start < 4)
	{
		g_nb = (g_nb << 1);
		if (c == '#')
		{
			if (str[g_i + g_j + 1] == '\n' && str[g_i + g_j + 2] == '#')
				return (-1);
			g_nb++;
			g_start++;
		}
	}
	g_j--;
	return (0);
}

int					create_array(char *str)
{
	int				len;
	int				r;

	g_i = 0;
	if ((len = ft_strlen(str)) == 0)
		return (-1);
	g_quantity = 0;
	g_tetrs = (t_tetriminos *)malloc(sizeof(t_tetriminos) * 26);
	while (g_i < len)
	{
		g_j = 19;
		g_nb = 0;
		g_start = -1;
		while (g_j >= 0)
			if ((r = valid_tetr(str, len) == -1))
				return (-1);
		if (!((str[g_i + 20] == '\n' && str[g_i + 21] != '\0')
			|| str[g_i + 20] == '\0'))
			return (-1);
		g_i += 21;
		g_tetrs[g_quantity++] = determine_tetr(g_nb);
		if (g_tetrs[g_quantity - 1] == 0)
			return (-1);
	}
	return (0);
}

int					main(int ac, char **av)
{
	int				fd;

	g_check = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (ac != 2)
	{
		write(1, "usage: ./fillit input_file\n", 28);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	read(fd, g_check, BUFF_SIZE - 1);
	g_check[BUFF_SIZE - 1] = '\0';
	if (create_array(g_check) != 0)
		write(1, "error\n", 6);
	else
	{
		solve(g_tetrs, g_quantity);
		print(g_mdim);
	}
	return (0);
}
