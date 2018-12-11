/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:58:34 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 16:29:57 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

#include <fcntl.h>
#include <stdlib.h> // do we need this for smthing ?
#include <unistd.h> // same
#include "libft.h"

typedef	unsigned short 	t_short;

typedef struct			s_field
{
	t_short				tab[16];
	int					size;
}						t_field;

int    					get_input(const int fd, t_short *tetris);
int 					print_error(char *str);
int 					check_counts(char *str, int count);
int 					check_links(char *str);
char 					*remove_lines(char *buf);
t_short					convert_tetro(char *s);

int						check_field(t_short *tetro);
int						check_tetro(t_short *tetro, t_field *field, int size);
int						fill_result(t_short *tetro, int pos, int size);

#endif
