#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

typedef	unsigned short 	t_short;

int						get_next_line(const int fd, char **line);

void 					print_tetro(t_short tetro);
t_short					convert_tetro(char *s);

int						move_tetros_pilot(t_short *tetro, int tetro_count);
int						move_tetros(t_short *tetro, t_short field[], int size);


#endif
