/*
** > Expects an array of shorts as parameter representing a set of tetrominoes
** > Returns an int representing the size of the minimum possible square
** that could hold the given set of tetrominoes in theory
*/

int		find_start_square(unsigned short tetrominoes[], size_t size)
{
	size_t i;
	unsigned short control;
	int pixels;

	i = 0;
	pixels = 0;
	while (i < size)
	{
		control = 0x1;
		while (control <= 0x8000)
		{
			if (tetrominoes[i] & control)
				pixels++;
			control *= 0x2;
		}
		i++;
	}
}



#include <stdio.h>
int main()
{
   	unsigned short	tetrominoes[] =
	{
		0xF000, 0x8888, 0xCC00, 0xC600, 0x4C80, 0xC880, 0xE200,
		0x44C0, 0x8E00, 0xE400, 0x4C40, 0x4E00, 0x8C80
	};
	printf("%d\n", find_start_square(tetrominoes, 13));	

}
