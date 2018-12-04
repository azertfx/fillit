/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:56:10 by anabaoui          #+#    #+#             */
/*   Updated: 2018/12/02 14:53:15 by anabaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct	trs_list
{
	int				tetris[2][4];
	int				id;
	struct trs_list	*next;
}				tr_list;
void			fillit(char *file);
int				check_file(char *file);
void			let_play(tr_list **t_list);

#endif
