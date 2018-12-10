#include <stdio.h>
#include "fillit.h"
#include <fcntl.h>
#include "libft.h"

int main(int argc, char **argv)
{
  t_short	tetro[27];
  t_short	*tetro_converted;

  if (argc != 2)
    return (print_error("usage: ./fillit [input_file]"));
  tetro_converted = get_input(open(argv[1], O_RDONLY), tetro);
  if (tetro_converted)
    {
      if (move_tetros_pilot(tetro) == -1)
	print_error("error");
      return (0);
    }
  print_error("error");
  return (0);
}
