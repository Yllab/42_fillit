/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:58:34 by hbally            #+#    #+#             */
/*   Updated: 2018/12/12 15:14:44 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h>
#include "libft.h"

typedef	unsigned short 	t_short;

typedef struct			s_tetros
{
	t_short				tab[27];
	int					size;
}						t_tetros;

typedef struct			s_field
{
	t_short				tab[16];
	int					size;
}						t_field;

int						get_input(const int fd, t_tetros *tetros);
int 					print_error(char *str);
int 					check_counts(char *str, int count);
int 					check_links(char *str);
char 					*remove_lines(char *buf);
t_short					convert_tetro(char *s);

int						check_field(t_tetros *tetros);
int						check_tetro(t_tetros *tetros,
									int current,
									t_field *field);
int						fill_result(t_tetros *tetros,
									int current,
									int pos,
									int field_size);

#endif
