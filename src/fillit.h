/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:56:10 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/18 19:16:25 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_lst
{
	int				tetris[2][4];
	int				id;
	struct s_lst	*next;
}				t_lst;
void			fillit(char *file);
int				check_file(char *file);
void			top_left(t_lst **trs_lst);
void			let_play(t_lst **trs_lst, int i);
void			remove_tetris(char **mr_tetris, t_lst **trs_lst);
void			move_tetris(int tb_list[2][4], int i);
void			fillit_result(char **mr_tetris);
int				matrix_dm(int tetris_nbr);

#endif
