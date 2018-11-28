#include "fillit.h"
#include "libft.h"

static	int			init_result(char **result, t_short *tetro, int size)
{
	int count;

	count = 0;
	while (*tetro)
	{
		tetro--;
		count++;
	}
	*result = ft_strnew(size * size);
	if (!*result)
		count = -1;
	return (count);
}

static void			print_result(char *result, int size)
{
	int				len;
	int				i;

	i = 0;
	len = size * size;
	while (i < len)
	{
		if (i > 0 && i % size == 0)
			ft_putchar('\n');
		if (!result[i])
			ft_putchar('.'); 
		else
			ft_putchar(result[i]);
		i++;
	}
	ft_putchar('\n');
	ft_strdel(&result);
}

int					fill_result(t_short *tetro, int pos, int size) 
{
	static char		*result;
	static int		count;
	t_short			iter;

	if (!result)
	{
		count = init_result(&result, tetro, size);
		if (count == -1)
			return (-1);
	}
	count--;
	iter = 0x8000;
	while (iter > 0)
	{
		if (*tetro & iter)
			result[pos] = 'A' + count;
		pos += iter & 0x1111 ? size - 3: 1;
		iter /= 2;
	}
	if (count == 0)
		print_result(result, size);
	return (1);
}
