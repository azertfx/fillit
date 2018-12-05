/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:10:17 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/05 15:04:34 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void	remove_tetris(char **mr_tetris, tr_list **t_list)
{
	int i;
	int j;

	printf("remove_tetris\n");
	i = 0;
	while (mr_tetris[i])
	{
		j = 0;
		while (mr_tetris[i][j])
		{
			if (mr_tetris[i][j] == ('A' + (*t_list)->id))
				mr_tetris[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		move_next_validate(int tb_list[2][4])
{
	int j;
	int i;

	printf("move_next_validate\n");
	printf("start\n");
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d | ", tb_list[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("----------------------\n");
	j = 0;
	while (j < 4)
	{
		if (tb_list[1][j] == 3)
		{
			move_tetris(tb_list, 1);
			j = 0;
			while (j < 4)
			{
				if (tb_list[0][j] == 3)
				{
					move_tetris(tb_list, 0);
					return (0);
				}
				j++;
			}
			if (j != 4)
			{
				j = 0;
				while (j < 4)
					tb_list[0][j++] += 1;
				return (1);
			}
		}
		j++;
	}
	j = 0;
	while (j < 4)
		tb_list[1][j++] += 1;
	printf("end\n");
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d | ", tb_list[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("----------------------\n");	
	return (1);
}

void	move_tetris(int tb_list[2][4], int i)
{
	int j;
	int	min;

	printf("move_tetris\n");
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

void	top_left(tr_list **t_list)
{
	tr_list *t_temp;

	printf("top_left\n");
	t_temp = *t_list;
	while (t_temp)
	{
		move_tetris(t_temp->tetris, 0);
		move_tetris(t_temp->tetris, 1);
		t_temp = t_temp->next;
	}
}
