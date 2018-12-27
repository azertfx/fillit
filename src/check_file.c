/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:15:58 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/18 19:41:58 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nearby(char *buff, int i, int *count)
{
	if (((i + 5) < 19) || ((i - 1) > 0) || ((i - 5) > 0))
	{
		(buff[i + 5] == '#') ? (*count)++ : ((*count) = (*count));
		(buff[i - 5] == '#') ? (*count)++ : ((*count) = (*count));
		(buff[i + 1] == '#') ? (*count)++ : ((*count) = (*count));
		(buff[i - 1] == '#') ? (*count)++ : ((*count) = (*count));
		return (1);
	}
	return (0);
}

int		check_nearby(char *buff, int *i, int *rf)
{
	int count;

	count = 0;
	while ((buff[*i] == '.' || buff[*i] == '#') ||
			(((*i + 1) % 5 == 0) && buff[*i] == '\n' && (*i != 0)))
	{
		if (buff[*i] == '#')
		{
			if (!(nearby(buff, *i, &count)))
				return (0);
			(*rf)++;
		}
		(*i)++;
	}
	if (*rf != 4 || count <= 4)
		return (0);
	return (1);
}

int		check_file(char *file)
{
	int		fd;
	int		rf;
	int		i;
	int		tetris;
	char	buff[22];

	i = 0;
	tetris = 0;
	fd = open(file, O_RDONLY);
	while ((rf = read(fd, buff, 21)) > 0)
	{
		buff[rf] = '\0';
		rf = 0;
		i = 0;
		if (!(check_nearby(buff, &i, &rf)))
			return (0);
		tetris++;
		if ((buff[i] && i != 20) || tetris > 26)
			return (0);
	}
	if (!buff[i] && i == 20)
		return (tetris);
	return (0);
}
