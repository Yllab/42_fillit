#include "fillit.h"

int main(int argc, char **argv)
{
  t_short	tetro[27];
  int fd;

  if (argc != 2)
    return (print_error("usage: ./fillit [input_file]"));
  fd = open(argv[1], O_RDONLY);
  if (!(get_input(fd, tetro)) || move_tetros_pilot(tetro) == -1)
    {
      print_error("error");
	  close(fd);
      return (0);
    }
  close(fd);
  return (0);
}
