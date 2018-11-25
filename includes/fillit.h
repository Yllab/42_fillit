#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32

//REMOVE IF SIZE_T IS NEVER USED IN PROTOTYPES
#include <string.h>

typedef struct			s_tetro
{
	unsigned short 		tetro;
	int					translate;
}						t_tetro;

int						get_next_line(const int fd, char **line);

void 					print_tetro(unsigned short tetro);
unsigned short			convert_tetro(char *s);
size_t					move_tetros(t_tetro *tetros, size_t tetro_count);


#endif
