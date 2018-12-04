/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:10:17 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/04 15:43:56 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
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

void	top_left(tr_list **t_list)
{
	tr_list *t_temp;

	t_temp = *t_list;
	while (t_temp)
	{
		move_tetris(t_temp->tetris, 0);
		move_tetris(t_temp->tetris, 1);
		t_temp = t_temp->next;
	}
}
