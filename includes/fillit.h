#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

int						get_next_line(const int fd, char **line);

void 					print_tetro(unsigned short tetro);
unsigned short			convert_tetro(char *s);

#endif
