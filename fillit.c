/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:58:09 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/06 20:11:33 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
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

tr_list	*new_list(int tb_list[2][4])
{
	tr_list		*t_list;
	static int	t_id = 0;

	if (!(t_list = (tr_list *)malloc(sizeof(tr_list))))
		return (0);
	tb_cpy(t_list->tetris, tb_list);
	t_list->id = t_id++;
	t_list->next = NULL;
	return (t_list);
}

int		fill_list(int tb_list[2][4], tr_list **t_list)
{
	tr_list	*t_temp;
	tr_list	*t_new;

	if (!(*t_list))
	{
		if (!(*t_list = new_list(tb_list)))
			return (0);
	}
	else
	{
		t_temp = *t_list;
		while (t_temp->next != NULL)
			t_temp = t_temp->next;
		if (!(t_new = new_list(tb_list)))
			return (0);
		t_temp->next = t_new;
	}
	return (1);
}

void	fill_tb(char **t_tab, tr_list **t_list)
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
	fill_list(tb_list, t_list);
}

void	fillit(char *file)
{
	int		fd;
	int		rf;
	char	buff[22];
	char	**t_tab;
	tr_list	*t_list;

	t_list = NULL;
	fd = open(file, O_RDONLY);
	if (check_file(file))
	{
		while ((rf = read(fd, buff, 21)) > 0)
		{
			buff[rf] = '\0';
			t_tab = ft_strsplit(buff, '\n');
			fill_tb(t_tab, &t_list);
		}
		let_play(&t_list, 4);
	}
	else
		ft_putstr("error\n");
}
