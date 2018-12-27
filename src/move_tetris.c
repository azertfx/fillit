/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:10:17 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/18 18:59:58 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		matrix_dm(int tetris_nbr)
{
	int i;

	i = 2;
	while ((4 * tetris_nbr) > (i * i))
		i++;
	return (i);
}

void	fillit_result(char **mr_tetris)
{
	int i;
	int j;

	i = 0;
	while (mr_tetris[i])
	{
		j = 0;
		while (mr_tetris[i][j])
		{
			ft_putchar(mr_tetris[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	remove_tetris(char **mr_tetris, t_lst **trs_lst)
{
	int i;
	int j;

	i = 0;
	while (mr_tetris[i])
	{
		j = 0;
		while (mr_tetris[i][j])
		{
			if (mr_tetris[i][j] == ('A' + (*trs_lst)->id))
				mr_tetris[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	move_tetris(int tb_list[2][4], int i)
{
	int j;
	int	min;

	j = 0;
	min = 3;
	while (j < 4)
	{
		if (tb_list[i][j] < min)
			min = tb_list[i][j];
		j++;
	}
	j = 0;
	while (j < 4)
		tb_list[i][j++] -= min;
}

void	top_left(t_lst **trs_lst)
{
	t_lst *t_temp;

	t_temp = *trs_lst;
	while (t_temp)
	{
		move_tetris(t_temp->tetris, 0);
		move_tetris(t_temp->tetris, 1);
		t_temp = t_temp->next;
	}
}
