/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:04:51 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/06 15:14:38 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
char	**g_matrix(int i)
{
	char	**tb_matrix;
	int		x;
	int		y;
	
	printf("g_matrix\n");
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
			printf("%c", tb_matrix[x][y]);
			y++;
		}
		printf("\n");
		tb_matrix[x][y] = '\0';
		x++;
	}
	printf("\n");
	tb_matrix[x] = 0;
	return (tb_matrix);
}

void	fill_mr(char **mr_tetris, int u, int v, tr_list **t_list)
{
	int i;
	int j;
	int x;
	int y;
	int len;

	printf("fill_mr\n");
	i = 0;
	j = 0;
	len = 0;
	while (len < 4)
	{
		x = (*t_list)->tetris[i++][j];
		y = (*t_list)->tetris[i--][j++];
		mr_tetris[x + u][y + v] = 'A' + (*t_list)->id;
		len++;
	}
	i = 0;
	while (mr_tetris[i])
	{
		j = 0;
		while (mr_tetris[i][j])
		{
			printf("%c", mr_tetris[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int		tetris_validate(char **mr_tetris, int u, int v, tr_list **t_list)
{
	int x;
	int y;
	int i;
	int j;
	int len;

	len = 0;
	i = 0;
	j = 0;
	while (len < 4)
	{
		printf("pp\n");
		x = (*t_list)->tetris[i++][j];
		y = (*t_list)->tetris[i--][j++];
		printf("x = %i y = %i\n",x,y);
		if (!mr_tetris[x + u])
			return (0);
		if (mr_tetris[x + u][y + v] != '.')
			return (0);
		len++;
	}
	fill_mr(mr_tetris, u, v, t_list);
	return (1);
}

int		validate_format(char **mr_tetris, tr_list **t_list)
{
	int		i;
	int		j;

	printf("validate_format\n");
	i = 0;
	if (!(*t_list))
		return (1);
	printf("go\n");
	while (mr_tetris[i])
	{
		j = 0;
		while (mr_tetris[i][j])
		{
			if (mr_tetris[i][j] == '.')
			{
				printf("i = %d , j = %d\n", i, j);
				if (tetris_validate(mr_tetris, i, j, t_list))
				{
					printf("ok\n");
					if(validate_format(mr_tetris, &(*t_list)->next))
						return (1);
					remove_tetris(mr_tetris, t_list);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	let_play(tr_list **t_list, int i)
{
	char	**final_tetris;
	tr_list *t_temp;

	printf("let_play\n");
	t_temp = *t_list;
	final_tetris = g_matrix(2 + i);
	top_left(&t_temp);
	if (validate_format(final_tetris, &t_temp))
	{
//		print_tetris();
		printf("done valide format\n");
	}
	else
	{
		printf("fail not valide\n");
		return let_play(t_list, ++i);
	}
}
