/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:15:58 by anabaoui          #+#    #+#             */
/*   Updated: 2018/11/25 18:45:56 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nearby(char *buff, int i)
{
	if (((i + 5) < 19) || ((i - 1) > 0) || ((i - 5) > 0))
	{
		if ((buff[i + 5] == '#') || (buff[i - 5] == '#')
				|| (buff[i + 1] == '#') || (buff[i - 1] == '#'))
			return (1);
	}
	return (0);
}

int		check_nearby(char *buff, int *i, int *rf)
{
	while ((buff[*i] == '.' || buff[*i] == '#') ||
			(((*i + 1) % 5 == 0) && buff[*i] == '\n' && (*i != 0)))
	{
		if (buff[*i] == '#')
		{
			if (!(nearby(buff, *i)))
				return (0);
			(*rf)++;
		}
		if (*rf > 4)
			return (0);
		(*i)++;
	}
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
		return (1);
	return (0);
}
