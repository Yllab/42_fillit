#include "libft.h"
#include "fillit.h"
#include <strings.h>

//-------------------------------------------------------
//TODO Remove when debug is done
void				print_field(unsigned short field[], size_t field_size)
{
	int	i;
	unsigned short ref = 0x8000;
	i = 0;
	while (i++ < field_size)
	{	
		while (ref)
		{
			if (field_size & ref)
				ft_putchar('1');
			else
				ft_putchar('0');
			ref /= 2;
		}
		ft_putchar('\n');
	}	
}
//-------------------------------------------------------

static int			BACKTRACKING_FUNCTION(t_tetro tetros,
								unsigned short field[], size_t field_size)
{
	return (1);
}

static void			field_init(unsigned short field[], size_t field_size)
{
	int 			i;

	i = 0;
	while (i < field_size)
		field[i++] = 0xFFFF >> field_size;
	while (i < 16)
		field[i++] = 0xFFFF;
}

size_t				move_tetros(t_tetro *tetros, size_t tetro_count)
{
	unsigned short	field[16];
	size_t			field_size;
	
//	field_size = ft_sqrt(tetro_count * 4);
	field_size = 10;
	field_init(field, field_size);
	print_field(field, field_size);
	while(!BACKTRACKING_FUNCTION(tetros, field, field_size))
	{
		field_size++;
		field_init(field_size);
	}
	return (field_size);
}
