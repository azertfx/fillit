/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:58:09 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/23 21:08:39 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		g_tetris = 0;

void	tb_cpy(int tb_list1[2][4], int tb_list2[2][4])
{
	int i;
	int j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			tb_list1[i][j] = tb_list2[i][j];
			j++;
		}
		i++;
	}
}

t_lst	*new_list(int tb_list[2][4])
{
	t_lst		*trs_lst;
	static int	t_id = 0;

	if (!(trs_lst = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	tb_cpy(trs_lst->tetris, tb_list);
	trs_lst->id = t_id++;
	trs_lst->next = NULL;
	return (trs_lst);
}

int		fill_list(int tb_list[2][4], t_lst **trs_lst)
{
	t_lst	*t_temp;
	t_lst	*t_new;

	if (!(*trs_lst))
	{
		if (!(*trs_lst = new_list(tb_list)))
			return (0);
	}
	else
	{
		t_temp = *trs_lst;
		while (t_temp->next != NULL)
			t_temp = t_temp->next;
		if (!(t_new = new_list(tb_list)))
			return (0);
		t_temp->next = t_new;
	}
	return (1);
}

void	fill_tb(char **t_tab, t_lst **trs_lst)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		tb_list[2][4];

	i = 0;
	x = 0;
	y = 0;
	while (t_tab[i])
	{
		j = 0;
		while (t_tab[i][j])
		{
			if (t_tab[i][j] == '#')
			{
				tb_list[x++][y] = i;
				tb_list[x--][y++] = j;
			}
			j++;
		}
		i++;
	}
	fill_list(tb_list, trs_lst);
}

void	fillit(char *file)
{
	int		fd;
	int		rf;
	char	buff[22];
	char	**t_tab;
	t_lst	*trs_lst;

	trs_lst = NULL;
	fd = open(file, O_RDONLY);
	if ((g_tetris = check_file(file)))
	{
		while ((rf = read(fd, buff, 21)) > 0)
		{
			buff[rf] = '\0';
			t_tab = ft_strsplit(buff, '\n');
			fill_tb(t_tab, &trs_lst);
		}
		let_play(&trs_lst, matrix_dm(g_tetris));
		while (trs_lst)
		{
			free(trs_lst);
			trs_lst = trs_lst->next;
		}
	}
	else
		ft_putstr("error\n");
}
