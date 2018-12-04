/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:04:51 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/04 17:45:36 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
char	**g_matrix(int i)
{
	char	**tb_matrix;
	int		x;
	int		y;
	
	x = 0;
	tb_matrix = (char **)malloc(sizeof(char *) * (i + 1));
	while (x < i)
		tb_matrix[x++] = (char *)malloc(sizeof(char) * (i + 1));
	x = 0;
	while (x < i)
	{
		y = 0;
		while (y < i)
		{
			tb_matrix[x][y] = '.';
			y++;
		}
		tb_matrix[x][y] = '\0';
		x++;
	}
	tb_matrix[x] = 0;
	return (tb_matrix);
}

int		validate_format(char **mr_tetris, char **t_list)
{

}

void	let_play(tr_list **t_list, int i)
{
	char	**final_tetris;

	final_tetris = g_matrix(2 + i);
	if (validate_format(final_tetris, t_list))
	{
//		print_tetris();
		printf("valide format\n");
	}
	else
	{
//		return let_play(t_list, ++i);
		printf("not valide\n");
	}
}
