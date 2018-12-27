/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:04:51 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/23 21:16:34 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	fill_mr(char **mr_tetris, int u, int v, t_lst **trs_lst)
{
	int i;
	int j;
	int x;
	int y;
	int len;

	i = 0;
	j = 0;
	len = 0;
	while (len < 4)
	{
		x = (*trs_lst)->tetris[i++][j];
		y = (*trs_lst)->tetris[i--][j++];
		mr_tetris[x + u][y + v] = 'A' + (*trs_lst)->id;
		len++;
	}
}

int		tetris_validate(char **mr_tetris, int u, int v, t_lst **trs_lst)
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
		x = (*trs_lst)->tetris[i++][j];
		y = (*trs_lst)->tetris[i--][j++];
		if (!mr_tetris[x + u])
			return (0);
		if (mr_tetris[x + u][y + v] != '.')
			return (0);
		len++;
	}
	fill_mr(mr_tetris, u, v, trs_lst);
	return (1);
}

int		validate_format(char **mr_tetris, t_lst **trs_lst, int dim)
{
	int		i;
	int		j;

	i = 0;
	if (!(*trs_lst))
		return (1);
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			if (tetris_validate(mr_tetris, i, j, trs_lst))
			{
				if (validate_format(mr_tetris, &(*trs_lst)->next, dim))
					return (1);
				remove_tetris(mr_tetris, trs_lst);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	let_play(t_lst **trs_lst, int i)
{
	char	**final_tetris;
	t_lst	*t_temp;
	int		x;

	x = 0;
	final_tetris = NULL;
	t_temp = *trs_lst;
	final_tetris = g_matrix(i);
	top_left(&t_temp);
	if (validate_format(final_tetris, &t_temp, i))
	{
		fillit_result(final_tetris);
		while (final_tetris[x])
			free(final_tetris[x++]);
	}
	else
		let_play(trs_lst, ++i);
}
