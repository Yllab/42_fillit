#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

int	print_error(char *str)
{
  ft_putendl(str);
  return (1);
}

int check_connections(char *str)
{
  int block;
  int i;

  block = 0;
  i = 0;
  while (i < 20)
    {
      if (str[i] == '#')
	{
	  if ((i + 1) < 20 && str[i + 1] == '#')
	    block++;
	  if ((i - 1) >= 0 && str[i - 1] == '#')
	    block++;
	  if ((i + 5) < 20 && str[i + 5] == '#')
	    block++;
	  if ((i - 5) >= 0 && str[i - 5] == '#')
	    block++;
	}
      i++;
    }
  return (block == 6 || block == 8);
}

int check_counts(char *str, int count)
{
  int i;
  int blocks;

  blocks = 0;
  i = 0;
  while (i < 20)
    {
      if (i % 5 < 4)
	{
	  if (!(str[i] == '#' || str[i] == '.'))
	    return (1);
	  if (str[i] == '#' && ++blocks > 4)
	    return (2);
	}
      else if (str[i] != '\n')
	return (3);
      i++;
    }
  if (count == 21 && str[20] != '\n')
    return (4);
  if (!check_connections(str))
    return (5);
  return (0);
}

char	*remove_lines(char *buf)
{
  char *str;
  int i;
  int j;

  i = 0;
  j = 0;
  str = ft_strnew(sizeof(buf));
  while (i < 16)
    {
      if (buf[j] != '\n')
	{
	  str[i] = buf[j];
	  i++;
	  j++;
	}
      else
	j++;
    }
  str[i] = '\0';
  return (str);
}

t_short	*get_input(const int fd, t_short *tetro)
{
  char buf[22];
  int count;
  int i;
  char check;
  char *tmp;

  i = 0;
  check = 0;
  tetro = 0;
  while ((count = read(fd, buf, 21)))
    {
      if (count < 20 || check_counts(buf, count) != 0)
	return (0);
      tmp = remove_lines(buf);
      //      tetro[i] = convert_tetro(tmp);
      check = count;
      if (i > 26)
	return (0);
      i++;
    }
  if (check != 20)
    return (0);
  return (tetro);
}
