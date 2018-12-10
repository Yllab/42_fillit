#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	unsigned short 	t_short;

typedef struct			s_field
{
	t_short				tab[16];
	int					size;
}						t_field;

//DEBUG -------------------

void					print_field(t_field *field, t_short *tetro, int pos, int print_tetro);
void 					print_tetro(t_short tetro);

//-------------------------

int						get_next_line(const int fd, char **line);

t_short					convert_tetro(char *s);
int						move_tetros_pilot(t_short *tetro);
int						move_tetros(t_short *tetro, t_field *field, int size);
int						fill_result(t_short *tetro, int pos, int size);
int    get_input(const int fd, t_short *tetris);
int print_error(char *str);
int check_counts(char *str, int count);
int check_links(char *str);
char *remove_lines(char *buf);

#endif
