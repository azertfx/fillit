/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:04:51 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/05 14:56:39 by anabaoui         ###   ########.fr       */
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
			y++;
		}
		tb_matrix[x][y] = '\0';
		x++;
	}
	tb_matrix[x] = 0;
	return (tb_matrix);
}

void	fill_mr(char **mr_tetris, tr_list **t_list)
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
		mr_tetris[x][y] = 'A' + (*t_list)->id;
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

int		tetris_validate(char **mr_tetris, tr_list **t_list, int id, int len)
{
	int i;
	int j;
	int	x;
	int y;
	int validate;
	tr_list *t_temp;

	printf("tetris_validate\n");
	i = 0;
	j = 0;
	t_temp = *t_list;
	while (t_temp->id != id)
		t_temp = t_temp->next;
	while (len < 4)
	{
		x = (*t_list)->tetris[i++][j];
		y = (*t_list)->tetris[i--][j++];
		if (mr_tetris[x][y] != '.')
		{
			validate = move_next_validate(t_temp->tetris);
			if(validate)
				return (tetris_validate(mr_tetris, &t_temp, t_temp->id, 0));
			return (0);
		}
		len++;
	}
	fill_mr(mr_tetris, t_list);
	return (1);
}

int		validate_format(char **mr_tetris, tr_list **t_list)
{
	tr_list *t_temp;

	printf("validate_format\n");
	t_temp = *t_list;
	if (tetris_validate(mr_tetris, &t_temp, t_temp->id, 0))
		validate_format(mr_tetris, &t_temp->next);
	if (move_next_validate(t_temp->tetris))
	{
		top_left(&t_temp);
		remove_tetris(mr_tetris, &t_temp);
		validate_format(mr_tetris, &t_temp->next);
	}
	return (0);
}

void	let_play(tr_list **t_list, int i)
{
	char	**final_tetris;
	tr_list *t_temp;

	printf("let_play\n");
	t_temp = *t_list;
	top_left(t_list);
	final_tetris = g_matrix(2 + i);
	if (validate_format(final_tetris, &t_temp))
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
