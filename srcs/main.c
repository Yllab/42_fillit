#include "fillit.h"
#include <fcntl.h>
#include "libft.h"

int main(int argc, char **argv)
{
  t_short	tetro[27];
  int fd;

  if (argc != 2)
    return (print_error("usage: ./fillit [input_file]"));
  ft_bzero(tetro, sizeof(t_short) * (27));
  fd = open(argv[1], O_RDONLY);
  if (!(get_input(fd, tetro)))
    {
      print_error("error");
      return (0);
    }
  close(fd);
  if (move_tetros_pilot(tetro) == -1)
    {
      print_error("error");
      return (0);
    }
  return (0);
}
