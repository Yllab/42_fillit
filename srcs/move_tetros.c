#include "libft.h"
#include "fillit.h"

//-------------------------------------------------------
//TODO Remove when debug is done
#include <stdio.h>
void				print_field(unsigned short field[])
{
	int	i;
	unsigned short ref;

	i = 0;
	while (i < 16)
	{	
		if (i < 10)
		printf("%d | ", i);
		else
		printf("%d| ", i);
		ref = 0x8000;
		while (ref)
		{
			if (field[i] & ref)
				printf("1 ");
			else
				printf("0 ");
			ref /= 2;
		}
		printf("\n");
		i++;
	}
	printf("\n");	
}

//-------------------------------------------------------

static int			BACKTRACKING_FUNCTION(t_tetro *tetros,
								unsigned short field[], int field_size)
{
	//DEBUG
	if (tetros == NULL)
	field[0] += 1;
	field[0] -= 1;
	field_size += 1;
	field_size -= 1;
	if (field_size > 16)
		return (1);
	return (0);
}

static void			field_init(unsigned short field[], int field_size)
{
	int 			i;

	i = 0;
	while (i < field_size)
		field[i++] = 0xFFFF >> field_size;
	while (i < 16)
		field[i++] = 0xFFFF;
}

int					move_tetros(t_tetro *tetros, int tetro_count)
{
	unsigned short	field[16];
	int				field_size;

	field_size = ft_sqrt(tetro_count * 4);
	field_init(field, field_size);
	while(!BACKTRACKING_FUNCTION(tetros, field, field_size))
	{
		field_size++;
		field_init(field, field_size);
	}
	return (field_size);
}
